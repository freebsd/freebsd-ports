# Created by: lintux@debian.org
# $FreeBSD$

PORTNAME=	rotix
PORTVERSION=	0.82
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://elektron.its.tudelft.nl/~hemmin98/rotix_releases/${DISTNAME}/

MAINTAINER=	lintux@debian.org
COMMENT=	A program to generate rotational obfuscations

DEPRECATED=	no longer maintained upstream
EXPIRATION_DATE=2013-09-20

USES=		gettext
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --i18n=1
CONFIGURE_ENV=	EXPR_COMPAT=1

MAN1=		rotix.1

PLIST_FILES=	bin/rotix share/locale/nl/LC_MESSAGES/rotix.mo

post-patch:
	@${REINPLACE_CMD} -e 's,%%CFLAGS%%,${CFLAGS},; s,%%LOCALBASE%%,${LOCALBASE},;' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
