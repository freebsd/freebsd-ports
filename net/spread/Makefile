# New ports collection makefile for:    spread
# Date created:		11 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	spread
PORTVERSION=	3.17.0
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	# fetch manually
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	joshua@roughtrade.net

GNU_CONFIGURE=	yes

MAN1=	spflooder.1 spmonitor.1 spread.1 sptuser.1 spuser.1
MAN3=	libsp.3 SP_connect.3 SP_disconnect.3 SP_equal_group_ids.3 SP_error.3 \
	SP_join.3 SP_leave.3 SP_multicast.3 SP_multigroup_multicast.3 \
	SP_multigroup_scat_multicast.3 SP_poll.3 SP_receive.3 \
	SP_scat_multicast.3 SP_scat_receive.3

USE_PERL5=	yes
INSTALLS_SHLIB=	yes
PKGMESSAGE=	${WRKSRC}/license.txt

MAKE_ARGS+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=         May not be automatically fetched due to licensin restrictions.\
		You MUST manually fetch the version after reading\
		and agreeing to the license at:\
		http://www.cnds.jhu.edu/download/download_spread.cgi\
		Once it has been downloaded, move it to ${DISTDIR}\
		and restart this build.
.endif

post-build:
	(cd ${WRKSRC}/perl/Spread; ${PERL} Makefile.PL; ${MAKE})

pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/spread.sh ${PREFIX}/etc/rc.d/spread.sh.sample
	${INSTALL_DATA} ${WRKSRC}/sp.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sp_func.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sp_events.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf ${PREFIX}/etc/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip ${PREFIX}/etc/spread.access_ip.sample
	(cd ${WRKSRC}/perl/Spread && ${MAKE} install)
	${GZIP_CMD} ${GZIP} ${LOCALBASE}/lib/perl5/${PERL_VERSION}/man/man3/Spread.3
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/LICENSE
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/perl/Spread/README ${DOCSDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/perl/Spread/test.pl ${DOCSDIR}/perl
.endif
	@${CAT} ${PKGMESSAGE}
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
