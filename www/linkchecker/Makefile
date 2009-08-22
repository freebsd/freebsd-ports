# ex:ts=8
# Ports collection makefile for:	linkchecker
# Date created:			Oct 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	linkchecker
PORTVERSION=	5.0.1
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	LinkChecker-${PORTVERSION}

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Check HTML documents for broken links

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	LinkChecker-${PORTVERSION}-${PYTHON_VERSION:S/thon//}.egg-info

MAN1=	linkchecker.1
MAN5=	linkcheckerrc.5

.if !defined(WITHOUT_NLS)
MANLANG=	"" de
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if !defined(WITHOUT_NLS)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/nls-patch-setup.py
.endif

.if !defined(WITHOUT_NLS)
post-install:
	${CP} ${WRKSRC}/build/share/locale/de/LC_MESSAGES/LinkChecker.mo ${PREFIX}/share/locale/de/LC_MESSAGES/
	${CP} ${WRKSRC}/build/share/locale/es/LC_MESSAGES/LinkChecker.mo ${PREFIX}/share/locale/es/LC_MESSAGES/
	${CP} ${WRKSRC}/build/share/locale/fr/LC_MESSAGES/LinkChecker.mo ${PREFIX}/share/locale/fr/LC_MESSAGES/
.endif

.include <bsd.port.mk>
