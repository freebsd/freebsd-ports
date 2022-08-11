PORTNAME=	sendxmpp
PORTVERSION=	1.24
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-im perl5

MAINTAINER=	mek@mek.uz.ua
COMMENT=	Perl script to send XMPP (Jabber) messages

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Net-XMPP>=0:net-im/p5-Net-XMPP
RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-Net-XMPP>=0:net-im/p5-Net-XMPP

USE_GITHUB=	yes
GH_ACCOUNT=	lhost

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PORTEXAMPLES=	send-url.xml sendxmpp-raw-messages
PLIST_FILES=	bin/sendxmpp ${SITE_MAN1}/sendxmpp.1.gz

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
