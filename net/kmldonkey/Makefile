# New ports collection makefile for:	KMLDonkey
# Date created:		Thu Feb 20 22:04:46 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmldonkey
PORTVERSION=	0.10.1
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.pre/pre/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE integration for MLDonkey eDonkey P2P client

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=''
INSTALLS_SHLIB=	yes

MAN1=	kmldonkey.1 kmldonkey_submit.1

pre-configure:
# disable AUTO* tools
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*(Makefile.in|configure)" \
		| ${XARGS} -x -n 10 \
		${REINPLACE_CMD} -E \
			-e 's!^(AUTOCONF|AUTOHEADER|AUTOMAKE|ACLOCAL).*$$!\1=${TRUE}!'

pre-build:
# disable AUTO* tools
	@${ECHO_CMD} > ${WRKSRC}/admin/cvs.sh

.include <bsd.port.mk>
