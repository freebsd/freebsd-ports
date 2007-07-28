# New ports collection makefile for:	kcheckgmail
# Date created:				17 June 2007
# Whom:					Yuan Jue <yuanjue@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kcheckgmail
PORTVERSION=	0.5.6
CATEGORIES=	mail kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.yuanjue.net/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yuanjue@FreeBSD.org
COMMENT=	A Gmail Notifier for KDE

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_KDELIBS_VER=3

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

post-patch:
	@${TOUCH} -t 200501251945 ${WRKSRC}/acinclude.m4
	@${TOUCH} -t 200704011036 ${WRKSRC}/aclocal.m4
	@${TOUCH} -t 200704011037 ${WRKSRC}/Makefile.in
	@${TOUCH} -t 200704011038 ${WRKSRC}/configure

.include <bsd.port.mk>
