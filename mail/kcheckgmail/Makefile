# New ports collection makefile for:	kcheckgmail
# Date created:				17 June 2007
# Whom:					YUAN Jue <yuanjue@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kcheckgmail
PORTVERSION=	0.5.7
PORTREVISION=	5
CATEGORIES=	mail kde
MASTER_SITES=	http://www.yuanjue.net/download/

MAINTAINER=	yuanjue@FreeBSD.org
COMMENT=	A Gmail Notifier for KDE

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_KDELIBS_VER=3
INSTALLS_ICONS=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

MAN1=		kcheckgmail.1

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/subdirs
.endif

.include <bsd.port.mk>
