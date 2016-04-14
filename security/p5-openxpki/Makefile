# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	openxpki
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter for PKI: universal server building block

LICENSE=	APACHE20

BUILD_DEPENDS=	\
	bash:shells/bash \
	openca-tools-forked>=1.4.0:security/openca-tools-forked \
	p5-CGI-Fast>=2.10:www/p5-CGI-Fast \
	p5-CGI-Session>=0:www/p5-CGI-Session \
	p5-CGI>=4.21:www/p5-CGI \
	p5-Class-Accessor-Chained>=0:devel/p5-Class-Accessor-Chained \
	p5-Class-Std>=0:devel/p5-Class-Std \
	p5-Config-GitLike>=0:devel/p5-Config-GitLike \
	p5-Config-Merge>=0:devel/p5-Config-Merge \
	p5-Config-Std>=0:devel/p5-Config-Std \
	p5-Connector>=0:devel/p5-Connector \
	p5-Crypt-CBC>=0:security/p5-Crypt-CBC \
	p5-Crypt-OpenSSL-AES>=0:security/p5-Crypt-OpenSSL-AES \
	p5-Crypt-PKCS10>=1.3:security/p5-Crypt-PKCS10 \
	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
	p5-DBD-Mock>=0:databases/p5-DBD-Mock \
	p5-Data-Password>=0:security/p5-Data-Password \
	p5-Data-Serializer>=0:devel/p5-Data-Serializer \
	p5-DateTime-Format-DateParse>=0:devel/p5-DateTime-Format-DateParse \
	p5-IO-Prompt>=0:devel/p5-IO-Prompt \
	p5-IPC-ShareLite>=0:devel/p5-IPC-ShareLite \
	p5-JSON>=0:converters/p5-JSON \
	p5-LWP-Protocol-connect>=0:www/p5-LWP-Protocol-connect \
	p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
	p5-Locale-libintl>=0:devel/p5-Locale-libintl \
	p5-Mail-RFC822-Address>=0:mail/p5-Mail-RFC822-Address \
	p5-Math-BigInt>=1.9993:math/p5-Math-BigInt \
	p5-Moose>=0:devel/p5-Moose \
	p5-Net-DNS>0.83:dns/p5-Net-DNS \
	p5-Net-IP>=0:net-mgmt/p5-Net-IP \
	p5-Net-Server>=0:net/p5-Net-Server \
	p5-NetAddr-IP>=0:net-mgmt/p5-NetAddr-IP \
	p5-Path-Class>=0:devel/p5-Path-Class \
	p5-Proc-ProcessTable>=0:devel/p5-Proc-ProcessTable \
	p5-Proc-SafeExec>=0:devel/p5-Proc-SafeExec \
	p5-RT-Client-REST>=0:www/p5-RT-Client-REST \
	p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
	p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
	p5-Switch>=0:lang/p5-Switch \
	p5-Sys-SigAction>=0:devel/p5-Sys-SigAction \
	p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
	p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
	p5-Test-Pod>=0:devel/p5-Test-Pod \
	p5-Test-Prereq>=0:devel/p5-Test-Prereq \
	p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
	p5-TimeDate>=0:devel/p5-TimeDate \
	p5-Workflow>=0.31:devel/p5-Workflow \
	p5-XML-Filter-XInclude>=0:textproc/p5-XML-Filter-XInclude \
	p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer \
	p5-XML-Validator-Schema>=0:textproc/p5-XML-Validator-Schema \
	p5-openxpki-i18n>=0.20.0.1:security/p5-openxpki-i18n \
	p5-perl-ldap>=0:net/p5-perl-ldap \

RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	\
	p5-openxpki-client-[0-9]* \
	p5-openxpki-client-scep-[0-9]* \
	p5-openxpki-client-deployment-[0-9]* \
	p5-openxpki-client-html-mason-[0-9]*

USE_GITHUB=	yes
USE_OPENSSL=	yes
USE_PERL5=	configure
USES=		gmake perl5
USE_RC_SUBR=	openxpki
SUB_FILES=	pkg-message
PORTDOCS=	*

WRKSRC_SUBDIR=	core/server

USERS=	openxpki
GROUPS=	openxpki

OPTIONS_DEFINE=	GRAPHVIZ DOCS EXAMPLES

GRAPHVIZ_DESC=	With graphical visualization of workflows?
GRAPHVIZ_RUN_DEPENDS=	dot:graphics/graphviz \
			imgsize:graphics/p5-Image-Size

post-patch:
	@${REINPLACE_CMD} -e 's|..ENV{PERL} .vergen --format version.|"${PORTVERSION}"|g' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e 's|..vergen --format version.|"${PORTVERSION}"|g' ${WRKSRC}/Makefile.PL
	@( \
	cd ${WRKSRC}/../..; \
	${FIND} config core/server doc qatest tools -type f -print0 >filelist; \
	${CAT} filelist | ${XARGS} -0 -I % ${REINPLACE_CMD} -e 's|/etc/openxpki|${PREFIX}/etc/openxpki|g' "%"; \
	${CAT} filelist | ${XARGS} -0 -I % ${REINPLACE_CMD} -e 's|/var/run/openxpkid.pid|/var/openxpki/openxpkid.pid|g' "%"; \
	${CAT} filelist | ${XARGS} -0 -I % ${REINPLACE_CMD} -e 's|/var/openxpki/\([^\.]*\)\.log|/var/log/openxpki/\1\.log|g' "%"; \
	${CAT} filelist | ${XARGS} -0 -I % ${RM} -f "%.bak"; \
	${RM} filelist; \
	)
	@${MKDIR} ${WRKSRC}/t/var/log/openxpki

post-stage:
	@${MKDIR} ${STAGEDIR}/var/openxpki/session
	@${MKDIR} ${STAGEDIR}/var/log/openxpki
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/openxpki

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_PORT) && defined(OPENSSL_PORT) && ${OPENSSL_PORT} == security/libressl
IGNORE=	this version of OpenXPKI is not fully functional with LibreSSL library, use OpenSSL instead
.endif

OXLIB=	${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/OpenXPKI/OpenXPKI.so

post-install:
	${STRIP_CMD} ${OXLIB}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/../.. && ${COPYTREE_SHARE} config ${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "htdocs cgi-bin" ${STAGEDIR}${EXAMPLESDIR})

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/../../doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
