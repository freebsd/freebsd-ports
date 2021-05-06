# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	duo_openvpn
PORTVERSION=	2.4
CATEGORIES=	security

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Duo two-factor authentication for OpenVPN

LICENSE=	GPLv2

RUN_DEPENDS=	openvpn>0:security/openvpn

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	duosecurity

CFLAGS+=	-DPREFIX='\"${DATADIR}\"'

SUB_FILES=	pkg-message

OPTIONS_SINGLE=	HELPER
OPTIONS_SINGLE_HELPER=	PERL PYTHON
OPTIONS_DEFAULT=PERL
OPTIONS_SUB=	yes

PERL_USES=		perl5
PERL_VARS=		USE_PERL5=run CFLAGS+=-DUSE_PERL
PERL_RUN_DEPENDS=	p5-JSON-XS>0:converters/p5-JSON-XS \
			p5-libwww>0:www/p5-libwww \
			p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https \
			p5-Digest-HMAC>0:security/p5-Digest-HMAC
PYTHON_USES=		python:3.7+,run

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} 's|%%SHEBANG%%|${PYTHON_CMD}|' ${WRKSRC}/duo_openvpn.py

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${WRKSRC}/duo_openvpn.so ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ca_certs.pem ${STAGEDIR}${DATADIR}

do-install-PERL-on:
	${INSTALL_SCRIPT} ${WRKSRC}/duo_openvpn.pl ${STAGEDIR}${DATADIR}

do-install-PYTHON-on:
	${INSTALL_SCRIPT} ${WRKSRC}/duo_openvpn.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/https_wrapper.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/six.py ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
