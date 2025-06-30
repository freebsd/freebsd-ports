PORTNAME=	microdc2
PORTVERSION=	0.15.6
PORTREVISION=	11
CATEGORIES=	net-p2p
MASTER_SITES=	http://vault.101011010.xyz/distfiles/ ${WWW:S,/h,if_&,} LOCAL/danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Command-line based Direct Connect client
WWW=		http://web.archive.org/web/20070214093745/http://corsair626.no-ip.org/microdc/

LICENSE=	GPLv2+

CONFLICTS=	tthsum

USES=		gnome iconv readline
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GNOME=	libxml2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-stage:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/pl/man1
	cd ${STAGEDIR}${PREFIX}/share/man && \
		${MV} man1/microdc.pl.1 pl/man1/microdc.1

.include <bsd.port.mk>
