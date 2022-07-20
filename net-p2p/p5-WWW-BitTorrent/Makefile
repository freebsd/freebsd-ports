PORTNAME=	WWW-BitTorrent
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	net-p2p perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Search and Download .torrent(s) files from BitTorrents boards

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww

USES=		perl5 shebangfix
SHEBANG_FILES=	bittorrent.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
