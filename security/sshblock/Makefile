# New ports collection makefile for:	sshblock
# Date created:				03 December 2006
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sshblock
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.bsdconsulting.no/tools/
EXTRACT_SUFX=	.pl

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Block abusive SSH login attempts

RUN_DEPENDS=	${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/sshblock
USE_PERL5=	yes
USE_RC_SUBR=	sshblock
SUB_LIST=	PERL=${PERL}
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
SUB_FILES+=	pkg-message
#SUB_FILES=	sshblock.sh

do-patch:
	@${REINPLACE_CMD} -e "s@/usr/bin/perl@${PERL}@" \
		${WRKSRC}/sshblock-${PORTVERSION}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sshblock-${PORTVERSION}.pl \
		${PREFIX}/sbin/sshblock

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
