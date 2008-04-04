# ex:ts=8
# Ports collection makefile for:	linkchecker
# Date created:			Oct 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	linkchecker
PORTVERSION=	4.8
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	beat@chruetertee.ch
COMMENT=	Check HTML documents for broken links

USE_PYTHON=		2.4+
USE_PYDISTUTILS=	yes

MAN1=	linkchecker.1
MAN5=	linkcheckerrc.5
MANLANG=	"" de

.if !defined(WITHOUT_NLS)
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
	${CP} ${WRKSRC}/build/share/locale/de/LC_MESSAGES/linkchecker.mo ${PREFIX}/share/locale/de/LC_MESSAGES/
	${CP} ${WRKSRC}/build/share/locale/es/LC_MESSAGES/linkchecker.mo ${PREFIX}/share/locale/es/LC_MESSAGES/
	${CP} ${WRKSRC}/build/share/locale/fr/LC_MESSAGES/linkchecker.mo ${PREFIX}/share/locale/fr/LC_MESSAGES/
.endif

.include <bsd.port.mk>
