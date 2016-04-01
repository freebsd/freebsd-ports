# Created by: Matteo Cypriani <mcy@lm7.fr>
# $FreeBSD$

PORTNAME=	renameutils
PORTVERSION=	0.12.0
CATEGORIES=	sysutils converters
MASTER_SITES=	SAVANNAH

MAINTAINER=	mcy@lm7.fr
COMMENT=	Rename files faster and more easily

LICENSE=	GPLv3

RUN_DEPENDS=	gls:sysutils/coreutils

GNU_CONFIGURE=	yes
USES=		readline charsetfix

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

# This should not be needed any more for the next upstream version
post-patch:
	@${REINPLACE_CMD} -e 's/($$bindir)/$$(bindir)/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
