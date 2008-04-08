# New ports collection makefile for:	vala
# Date created:		2007-07-09
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/lang/vala/Makefile,v 1.1 2007/11/30 19:17:16 marcus Exp $
#

PORTNAME=	vala
PORTVERSION=	0.2.0
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

OPTIONS=	VAPIGEN "Enable VAPI generator" Off
USE_BZIP2=	yes
USE_GNOME=	glib20 gnomeprefix libxslt
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}" LDFLAGS="-L${LOCALBASE}/lib"
USE_BISON=	build
MAN1=		valac.1
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_VAIPGEN)
CONFIGURE_ARGS+=	--enable-vapigen
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
PLIST_SUB+=	VAPIGEN=""
.else
CONFIGURE_ARGS+=	--disable-vapigen
PLIST_SUB+=	VAPIGEN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
