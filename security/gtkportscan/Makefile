# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkportscan
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	LOCAL/cpiazza

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple port scanner that prints out open ports

OPTIONS_DEFINE=	GTK2

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/gtkportscan bin/portscan

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
USES+=		pkgconfig
GTK_CONFIG=	pkg-config gtk+-2.0
.else
USE_GNOME=	gtk12
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^void main|int main|' ${WRKSRC}/portscan.c

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o portscan portscan.c)
	(cd ${WRKSRC} && ${CC} ${CFLAGS} $$(${GTK_CONFIG} --cflags) \
		-o gtkportscan gtkportscan.c $$(${GTK_CONFIG} --libs))

do-install:
.for i in gtkportscan portscan
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} ${PREFIX}/bin)
.endfor

.include <bsd.port.mk>
