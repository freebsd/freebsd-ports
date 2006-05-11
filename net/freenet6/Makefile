# New ports collection makefile for:   freenet6
# Date created:        11 Oct 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	freenet6
PORTVERSION=	2.1.1
PORTREVISION=	6
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.hexago.com/files/
DISTNAME=	tspc-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Freenet6 Tunnel Setup Protocol Client - Free IPv6 tunnel

USE_RC_SUBR=	yes
WRKSRC=		${WRKDIR}/tspc2

MAN8=		tspc.8
MAN5=		tspc.conf.5

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	freenet6.sh pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
IGNORE=		This program might not be working on FreeBSD version below 4.0
.endif
.if ${OSVERSION} > 500000
EXTRA_PATCHES=	${FILESDIR}/patch5-template::freebsd.sh
.endif

MAKE_ARGS=	target=freebsd installdir=${PREFIX}

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/bin/tspc.conf.sample ${EXAMPLESDIR}

	@${INSTALL_PROGRAM} ${WRKSRC}/bin/tspc ${PREFIX}/bin/tspc
	@${INSTALL_SCRIPT} ${WRKSRC}/template/checktunnel.sh ${PREFIX}/bin/checktunnel.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/template/freebsd.sh ${PREFIX}/bin/tspc-freebsd.sh
	@${INSTALL_MAN} ${WRKSRC}/man/man8/tspc.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/man/man5/tspc.conf.5 ${PREFIX}/man/man5
	@${INSTALL_SCRIPT} ${WRKDIR}/freenet6.sh ${PREFIX}/etc/rc.d/

post-install:
	@${CAT} ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} \
		-e "s|/installdir/bin|${PREFIX}/etc|g" \
		${WRKSRC}/man/man8/tspc.8

	@${REINPLACE_CMD} \
		-e "s|/usr/local/tsp|${PREFIX}|g" \
		-e "s|/install/dir/bin/tspc.conf.sample|${EXAMPLESDIR}/tspc.conf.sample|g" \
		-e "s|/install/dir/bin/tspc.conf|${PREFIX}/etc/tspc.conf|g" \
		-e "s|template=linux|template=tspc-freebsd|g" \
		${WRKSRC}/man/man5/tspc.conf.5

.include <bsd.port.post.mk>
