# New ports collection makefile for:    spread
# Date created:		11 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	spread
PORTVERSION=	3.16.2
CATEGORIES=	net perl5 java
MASTER_SITES=	http://www.roughtrade.net/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	joshua@roughtrade.net

MAKEFILE=	FreeBSD_makefile

MAN1=	spflooder.1 spmonitor.1 spread.1 sptuser.1 spuser.1
MAN3=	libsp.3 SP_connect.3 SP_disconnect.3 SP_equal_group_ids.3 SP_error.3 \
	SP_join.3 SP_leave.3 SP_multicast.3 SP_multigroup_multicast.3 \
	SP_multigroup_scat_multicast.3 SP_poll.3 SP_receive.3 \
	SP_scat_multicast.3 SP_scat_receive.3

.if defined(WITH_JAVA_LIB)
USE_JAVA=	1.2+
.endif
USE_PERL5=	yes
INSTALLS_SHLIB=	yes
PKGMESSAGE=	${WRKSRC}/license.txt

JAVALIBDIR=	${PREFIX}/share/java/classes

.if defined(WITH_JAVA_LIB)
PLIST_SUB+=	JAVALIB='' JAVALIBDIR=share/java/classes
.if defined(NOPORTDOCS)
PLIST_SUB+=	JAVALIB_DOCS='@comment '
.else
PLIST_SUB+=	JAVALIB_DOCS=''
.endif
.else
PLIST_SUB+=	JAVALIB='@comment ' JAVALIB_DOCS='@comment ' JAVALIBDIR=''
.endif

MAKE_ARGS+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

post-patch:
.for f in configuration.c auth-ip.c auth-pword.c docs/spread.1 \
	docs/spmonitor.1 Readme.txt
	@${PERL} -pi -e 's,/etc/spread,${PREFIX}/etc/spread,g' ${WRKSRC}/${f}
.endfor

post-build:
	(cd ${WRKSRC}/perl/Spread; ${PERL} Makefile.PL; ${MAKE})
.if defined(WITH_JAVA_LIB)
	(cd ${WRKSRC}/java; CLASSPATH=${JAVA_CLASSES} ${JAVAC} spread/*.java -d ./)
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/java; ${MKDIR} docs; \
	${JAVADOC} -sourcepath spread/ -verbose -windowtitle 'Spread for Java' \
		-nodeprecated -d docs/ spread/*.java)
.endif
.endif

pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spread ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/spflooder ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spmonitor ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spuser ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sptuser ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libsp.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libtsp.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/sp.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sp_func.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sp_events.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf ${PREFIX}/etc/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip ${PREFIX}/etc/spread.access_ip.sample
	(cd ${WRKSRC}/perl/Spread && ${MAKE} install)
	${GZIP_CMD} ${GZIP} ${LOCALBASE}/lib/perl5/${PERL_VERSION}/man/man3/Spread.3
.if defined(WITH_JAVA_LIB)
	${INSTALL} -d -o root -g wheel -m 0755 ${JAVALIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/java/spread/*.class ${JAVALIBDIR}/${PORTNAME}
.endif
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/${f} ${PREFIX}/man/man1
.endfor
.for f in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/docs/${f} ${PREFIX}/man/man3
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/LICENSE
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/perl/Spread/README ${DOCSDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/perl/Spread/test.pl ${DOCSDIR}/perl
.if defined(WITH_JAVA_LIB)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/java
	${INSTALL_DATA} ${WRKSRC}/java/readme.txt ${DOCSDIR}/java
	${INSTALL_DATA} ${WRKSRC}/java/recThread.java ${DOCSDIR}/java
	${INSTALL_DATA} ${WRKSRC}/java/Flooder.java ${DOCSDIR}/java
	${INSTALL_DATA} ${WRKSRC}/java/User.java ${DOCSDIR}/java
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/java/html
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/java/html/spread
	${INSTALL_DATA} ${WRKSRC}/java/docs/*.html ${DOCSDIR}/java/html
	${INSTALL_DATA} ${WRKSRC}/java/docs/stylesheet.css ${DOCSDIR}/java/html
	${INSTALL_DATA} ${WRKSRC}/java/docs/spread/*.html ${DOCSDIR}/java/html/spread
.endif
.endif
	@${CAT} ${PKGMESSAGE}

post-install:
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
