# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	openxpki
PORTVERSION=	0.21.0.1
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: server and deployment

LICENSE=	APACHE20

BUILD_DEPENDS=	\
	p5-openxpki-i18n>=0.20.0.1:${PORTSDIR}/security/p5-openxpki-i18n \
	openca-tools-forked>=1.4.0:${PORTSDIR}/security/openca-tools-forked \
	p5-Class-Accessor-Chained>=0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
	p5-Config-Merge>=0:${PORTSDIR}/devel/p5-Config-Merge \
	p5-Connector>=0:${PORTSDIR}/devel/p5-Connector \
	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
	p5-Crypt-OpenSSL-AES>=0:${PORTSDIR}/security/p5-Crypt-OpenSSL-AES \
	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
	p5-LWP-Protocol-connect>=0:${PORTSDIR}/www/p5-LWP-Protocol-connect \
	p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Proc-SafeExec>=0:${PORTSDIR}/devel/p5-Proc-SafeExec \
	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
	p5-Switch>=0:${PORTSDIR}/lang/p5-Switch \
	p5-Workflow>=0.31:${PORTSDIR}/devel/p5-Workflow \
	p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
	p5-Locale-libintl>=0:${PORTSDIR}/devel/p5-Locale-libintl \
	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
	p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
	p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
	p5-XML-Filter-XInclude>=0:${PORTSDIR}/textproc/p5-XML-Filter-XInclude \
	p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
	p5-XML-Validator-Schema>=0:${PORTSDIR}/textproc/p5-XML-Validator-Schema \
	p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
	p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
	p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
	p5-Class-Std>=0:${PORTSDIR}/devel/p5-Class-Std \
	p5-Mail-RFC822-Address>=0:${PORTSDIR}/mail/p5-Mail-RFC822-Address \
	p5-Proc-ProcessTable>=0:${PORTSDIR}/devel/p5-Proc-ProcessTable \
	p5-Sys-SigAction>=0:${PORTSDIR}/devel/p5-Sys-SigAction \
	p5-Data-Password>=0:${PORTSDIR}/security/p5-Data-Password \
	p5-RT-Client-REST>=0:${PORTSDIR}/www/p5-RT-Client-REST \
	p5-Data-Serializer>=0:${PORTSDIR}/devel/p5-Data-Serializer \
	p5-IPC-ShareLite>=0:${PORTSDIR}/devel/p5-IPC-ShareLite \
	p5-DateTime-Format-DateParse>=0:${PORTSDIR}/devel/p5-DateTime-Format-DateParse \
	p5-IO-Prompt>=0:${PORTSDIR}/devel/p5-IO-Prompt \
	p5-Config-Std>=0:${PORTSDIR}/devel/p5-Config-Std \
	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-NetAddr-IP>=0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	\
	p5-openxpki-client-[0-9]* \
	p5-openxpki-client-scep-[0-9]* \
	p5-openxpki-client-deployment-[0-9]* \
	p5-openxpki-client-html-mason-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
GH_PROJECT=	openxpki
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	908559d

USE_OPENSSL=	yes
USE_PERL5=	configure
USES=		gmake perl5
USE_RC_SUBR=	openxpki

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/core/server

USERS=	openxpki
GROUPS=	openxpki

OPTIONS_DEFINE=	GRAPHVIZ

GRAPHVIZ_DESC=	With graphical visualization of workflows?
GRAPHVIZ_RUN_DEPENDS=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz \
			${LOCALBASE}/bin/imgsize:${PORTSDIR}/graphics/p5-Image-Size

post-patch:
	@${REINPLACE_CMD} -e 's|..vergen --format version.|"${PORTVERSION:R}"|g' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/OpenXPKI/OpenXPKI.so

.include <bsd.port.mk>
