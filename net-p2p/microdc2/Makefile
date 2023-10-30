PORTNAME=	microdc2
PORTVERSION=	0.15.6
PORTREVISION=	10
CATEGORIES=	net-p2p
MASTER_SITES=	http://corsair626.no-ip.org/microdc/ LOCAL/danfe

MAINTAINER=	pankov_p@mail.ru
COMMENT=	Command-line based Direct Connect client
WWW=		http://corsair626.no-ip.org/microdc/

LICENSE=	GPLv2

CONFLICTS=	tthsum

USES=		gnome iconv readline
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-stage:
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/pl/man1
	cd ${STAGEDIR}${MANPREFIX}/man && \
		${MV} man1/microdc.pl.1 pl/man1/microdc.1

.include <bsd.port.mk>
