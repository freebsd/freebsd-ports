# New ports collection makefile for:    spread
# Date created:		11 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	spread
PORTVERSION=	3.15.2
CATEGORIES=	net perl5 java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

.if defined(WITH_JAVA_LIB)
BUILD_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk
.endif

MAKEFILE=	FreeBSD_makefile

MAN1=	spread.1
MAN3=	SP_connect.3 SP_disconnect.3 SP_equal_group_ids.3 SP_error.3 \
	SP_join.3 SP_leave.3 SP_multicast.3 SP_multigroup_multicast.3 \
	SP_multigroup_scat_multicast.3 SP_poll.3 SP_receive.3 \
	SP_scat_multicast.3 SP_scat_receive.3

USE_PERL5=	yes
NO_PACKAGE=	"User and group needs to be created"
INSTALLS_SHLIB=	yes

JAVASUBDIR=	jdk1.1.8
JAVADIR=	${PREFIX}/${JAVASUBDIR}
JAVALIBDIR=	${JAVADIR}/lib
DOCDIR=		${PREFIX}/share/doc/${PORTNAME}

.if defined(WITH_JAVA_LIB)
PLIST_SUB+=	JAVALIB='' JAVALIBDIR=${JAVASUBDIR}/lib
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

post-build:
	(cd ${WRKSRC}/perl/Spread-3.15.2-1.03; ${PERL} Makefile.PL; ${MAKE})
.if defined(WITH_JAVA_LIB)
	(cd ${WRKSRC}/java; ${JAVADIR}/bin/javac \
	splib_src/*.java -d ./)
.endif

do-install:
	@${SH} ${SCRIPTDIR}/createusergroup
	${INSTALL_PROGRAM} ${WRKSRC}/spread ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/flooder ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/monitor ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/user ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tuser ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libsp.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libtsp.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/sp.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf ${PREFIX}/etc/spread.conf.example
	${INSTALL_MAN} ${WRKSRC}/docs/spread.1 ${PREFIX}/man/man1
	(cd ${WRKSRC}/perl/Spread-3.15.2-1.03 && ${MAKE} install)
	${GZIP_CMD} ${GZIP} ${LOCALBASE}/lib/perl5/${PERL_VERSION}/man/man3/Spread.3
.if defined(WITH_JAVA_LIB)
	${INSTALL} -d -o root -g wheel -m 0755 ${JAVALIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/java/spread/*.class ${JAVALIBDIR}/${PORTNAME}
.endif
.for f in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/docs/${f} ${PREFIX}/man/man3
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCDIR}
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/perl/Spread-3.15.2-1.03/README ${DOCDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/perl/Spread-3.15.2-1.03/test.pl ${DOCDIR}/perl
.if defined(WITH_JAVA_LIB)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCDIR}/java
	${INSTALL_DATA} ${WRKSRC}/java/readme.txt ${DOCDIR}/java
	${INSTALL_DATA} ${WRKSRC}/java/Flooder.java ${DOCDIR}/java
	${INSTALL_DATA} ${WRKSRC}/java/User.java ${DOCDIR}/java
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCDIR}/java/html
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCDIR}/java/html/spread
	${INSTALL_DATA} ${WRKSRC}/java/docs/*.html ${DOCDIR}/java/html
	${INSTALL_DATA} ${WRKSRC}/java/docs/stylesheet.css ${DOCDIR}/java/html
	${INSTALL_DATA} ${WRKSRC}/java/docs/spread/*.html ${DOCDIR}/java/html/spread
.endif
.endif
	@${ECHO} "================================================================================"
	@${ECHO} "NB: Create the directory /var/run/spread, with write permissions for the spread"
	@${ECHO} "user/group. The spread daemon will chroot there, and fail if it can't."
	@${ECHO} "================================================================================"

.include <bsd.port.post.mk>
