# New ports collection makefile for:	gringotts
# Date created:				02 July 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gringotts
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://devel.pluto.linux.it/projects/Gringotts/current/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	GTK application to securely store sensitive data

LIB_DEPENDS=	gringotts.2:${PORTSDIR}/security/libgringotts \
		gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
WANT_GNOME=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--disable-env-check

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier}!=""
USE_GNOME+=	gnomehier
PLIST_SUB+=	GNOMEHIER=''
.else
PLIST_SUB+=	GNOMEHIER='@comment '
.endif

post-patch:
	${REINPLACE_CMD} -E -e "s|^(gringottsdocdir =).*|\1 $$\(datadir\)/doc/gringotts|;s|md5sum|md5|g" ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -E -e "s|^(install-data-am:.*)install-gringottsdocDATA|\1|" ${WRKSRC}/Makefile.in
.endif
.if ${HAVE_GNOME:Mgnomehier}==""
	${REINPLACE_CMD} -E -e "s|^(install-data-am:.*)install-DsktpDATA|\1|" \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
