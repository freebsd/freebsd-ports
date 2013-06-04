# Created by: YUAN Jue <yuanjue@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kcheckgmail
PORTVERSION=	0.5.7
PORTREVISION=	6
CATEGORIES=	mail kde
MASTER_SITES=	http://www.yuanjue.net/download/

MAINTAINER=	yuanjue@FreeBSD.org
COMMENT=	A Gmail Notifier for KDE

BROKEN=		checksum mismatch

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_KDELIBS_VER=3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

MAN1=		kcheckgmail.1

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/subdirs
.endif

.include <bsd.port.mk>
