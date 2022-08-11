PORTNAME=	cronolog
PORTVERSION=	1.6.2
PORTREVISION=	6
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web log rotation utility that provides datestamp filenames

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	cronolog-devel

INFO=		cronolog
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fordmason
GH_TAGNAME=	8ea64c0

OPTIONS_DEFINE=		SETUID_PATCH
OPTIONS_DEFAULT=	SETUID_PATCH
SETUID_PATCH_DESC=	Build with setuid functionality
SETUID_PATCH_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-cronolog-setugid

post-patch-SETUID_PATCH-on:
	(cd ${WRKSRC} && ${TOUCH} aclocal.m4 Makefile.in */Makefile.in)

.include <bsd.port.mk>
