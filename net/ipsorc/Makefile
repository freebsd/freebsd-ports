# $FreeBSD$

PORTNAME=	ipsorc
PORTVERSION=	1.7.5
PORTREVISION=	7
CATEGORIES=	net security
MASTER_SITES=	http://200ok.org/distfiles/ipsorc/ \
		http://bsdforge.com/projects/source/net/ipsorcery/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	GTK GUI tool to create and send IP packets

LICENSE=	GPLv2

USE_GNOME=	gtk12
USES=		tar:bzip2

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README HOWTO
PROGRAMS=	ipmagic magic
PLIST_FILES=	bin/ipmagic bin/magic

post-patch:
	@${REINPLACE_CMD} -e 's,gtk-config,${GTK_CONFIG},' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
