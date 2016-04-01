# Created by: ultima <ultima1252@gmail.com>
# $FreeBSD$

PORTNAME=	plexWatch
PORTVERSION=	0.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Notify, Log Now Playing and Watched content from a Plex Media Server

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-DBI>=0:databases/p5-DBI \
		p5-Time-Duration>=0:devel/p5-Time-Duration \
		p5-Time-modules>=0:devel/p5-Time-modules \
		p5-JSON>=0:converters/p5-JSON \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https

USES=		perl5 shebangfix
SHEBANG_FILES=	plexWatch.pl

USE_GITHUB=	yes
GH_ACCOUNT=	ljunkie
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EMAIL GNTP IPLOG TWITTER
OPTIONS_DEFAULT=

EMAIL_RUN_DEPENDS=	p5-Net-SMTPS>=0:mail/p5-Net-SMTPS
EMAIL_DESC=		Email support

GNTP_RUN_DEPENDS=	p5-Growl-GNTP>=0:net/p5-Growl-GNTP
GNTP_DESC=		Growl GNTP support

IPLOG_RUN_DEPENDS=	p5-File-ReadBackwards>=0:devel/p5-File-ReadBackwards
IPLOG_DESC=		Client IP logging support

TWITTER_RUN_DEPENDS=	p5-Net-Twitter-Lite>=0:net/p5-Net-Twitter-Lite \
			p5-Net-OAuth>=0:net/p5-Net-OAuth
TWITTER_DESC=		Twitter support

post-patch:
	${REINPLACE_CMD} "s|%%ETCDIR%%|${ETCDIR}|" ${WRKSRC}/plexWatch.pl
	${REINPLACE_CMD} "s|/opt/plexWatch|${DATADIR}|" ${WRKSRC}/config.pl-dist

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} -m 777 ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/plexWatch.pl ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/config.pl-dist ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
