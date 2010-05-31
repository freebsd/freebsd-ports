# ex:ts=8
# Ports collection makefile for:	linkchecker
# Date created:			Oct 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	linkchecker
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
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
.else
	@${RM} ${WRKSRC}/po/*.po
.endif

.include <bsd.port.mk>
