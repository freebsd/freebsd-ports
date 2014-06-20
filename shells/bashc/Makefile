# Created by: alepulver
# $FreeBSD$

PORTNAME=	bashc
PORTVERSION=	3.2.33.0
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU bash shell extended with visual two-panel file browser

MAKE_JOBS_UNSAFE=	yes

USES=		tar:tgz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bashc \
		etc/bash_commander \
		etc/bash_dialog

post-patch:
	@${REINPLACE_CMD} -e 's|autoconf|${TRUE}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
