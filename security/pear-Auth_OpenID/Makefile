# New ports collection makefile for:	php-openid
# Date created:		2008-03-03
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Auth_OpenID
PORTVERSION=	2.1.3
CATEGORIES=	security www pear
MASTER_SITES=	http://openidenabled.com/files/php-openid/packages/
DISTNAME=	php-openid-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	PHP OpenID library v2 for PEAR

RUN_DEPENDS=	pear:${PORTSDIR}/devel/pear
BUILD_DEPENDS=	${RUN_DEPENDS}

CONFLICTS=	php-Auth_OpenID-1.*

USE_BZIP2=	yes
LATEST_LINK=	pear-Auth_OpenID

WRKSRC=		${WRKDIR}/php-openid-${PORTVERSION}

OPTIONS=	BCMATH "Use bcmath instead of libgmp" off \
		PEAR_DB "Support SQL stores" off

USE_PHP=	curl dom
USE_PYTHON_BUILD=	yes

FILES=		Auth/OpenID.php Auth/OpenID/AX.php \
		Auth/OpenID/Association.php Auth/OpenID/BigMath.php \
		Auth/OpenID/Consumer.php Auth/OpenID/CryptUtil.php \
		Auth/OpenID/DatabaseConnection.php \
		Auth/OpenID/DiffieHellman.php Auth/OpenID/Discover.php \
		Auth/OpenID/DumbStore.php Auth/OpenID/Extension.php \
		Auth/OpenID/FileStore.php Auth/OpenID/HMAC.php \
		Auth/OpenID/Interface.php Auth/OpenID/KVForm.php \
		Auth/OpenID/MemcachedStore.php \
		Auth/OpenID/Message.php Auth/OpenID/MySQLStore.php \
		Auth/OpenID/Nonce.php Auth/OpenID/PAPE.php \
		Auth/OpenID/Parse.php Auth/OpenID/PostgreSQLStore.php \
		Auth/OpenID/SQLStore.php Auth/OpenID/SQLiteStore.php \
		Auth/OpenID/SReg.php Auth/OpenID/Server.php \
		Auth/OpenID/ServerRequest.php Auth/OpenID/TrustRoot.php \
		Auth/OpenID/URINorm.php \
		Auth/Yadis/HTTPFetcher.php Auth/Yadis/Manager.php \
		Auth/Yadis/Misc.php Auth/Yadis/ParanoidHTTPFetcher.php \
		Auth/Yadis/ParseHTML.php Auth/Yadis/PlainHTTPFetcher.php \
		Auth/Yadis/XML.php Auth/Yadis/XRDS.php Auth/Yadis/XRI.php \
		Auth/Yadis/XRIRes.php Auth/Yadis/Yadis.php

DOCS=		OpenID/Auth_OpenID_AX.html \
		OpenID/Auth_OpenID_AX_AttrInfo.html \
		OpenID/Auth_OpenID_AX_Error.html \
		OpenID/Auth_OpenID_AX_FetchRequest.html \
		OpenID/Auth_OpenID_AX_FetchResponse.html \
		OpenID/Auth_OpenID_AX_KeyValueMessage.html \
		OpenID/Auth_OpenID_AX_Message.html \
		OpenID/Auth_OpenID_AX_StoreRequest.html \
		OpenID/Auth_OpenID_AX_StoreResponse.html \
		OpenID/Auth_OpenID_AlreadySigned.html \
		OpenID/Auth_OpenID_AssociateRequest.html \
		OpenID/Auth_OpenID_Association.html \
		OpenID/Auth_OpenID_AuthRequest.html \
		OpenID/Auth_OpenID_CancelResponse.html \
		OpenID/Auth_OpenID_CheckAuthRequest.html \
		OpenID/Auth_OpenID_CheckIDRequest.html \
		OpenID/Auth_OpenID_Consumer.html \
		OpenID/Auth_OpenID_ConsumerResponse.html \
		OpenID/Auth_OpenID_DatabaseConnection.html \
		OpenID/Auth_OpenID_Decoder.html \
		OpenID/Auth_OpenID_DiffieHellmanSHA1ConsumerSession.html \
		OpenID/Auth_OpenID_DiffieHellmanSHA1ServerSession.html \
		OpenID/Auth_OpenID_DiffieHellmanSHA256ConsumerSession.html \
		OpenID/Auth_OpenID_DiffieHellmanSHA256ServerSession.html \
		OpenID/Auth_OpenID_DumbStore.html \
		OpenID/Auth_OpenID_Encoder.html \
		OpenID/Auth_OpenID_EncodingError.html \
		OpenID/Auth_OpenID_Extension.html \
		OpenID/Auth_OpenID_FailureResponse.html \
		OpenID/Auth_OpenID_FileStore.html \
		OpenID/Auth_OpenID_GenericConsumer.html \
		OpenID/Auth_OpenID_MalformedReturnURL.html \
		OpenID/Auth_OpenID_MalformedTrustRoot.html \
		OpenID/Auth_OpenID_Mapping.html \
		OpenID/Auth_OpenID_MemcachedStore.html \
		OpenID/Auth_OpenID_Message.html \
		OpenID/Auth_OpenID_MySQLStore.html \
		OpenID/Auth_OpenID_NamespaceMap.html \
		OpenID/Auth_OpenID_NoReturnToError.html \
		OpenID/Auth_OpenID_OpenIDStore.html \
		OpenID/Auth_OpenID_PAPE_Request.html \
		OpenID/Auth_OpenID_PAPE_Response.html \
		OpenID/Auth_OpenID_PlainTextConsumerSession.html \
		OpenID/Auth_OpenID_PlainTextServerSession.html \
		OpenID/Auth_OpenID_PostgreSQLStore.html \
		OpenID/Auth_OpenID_Request.html \
		OpenID/Auth_OpenID_SQLStore.html \
		OpenID/Auth_OpenID_SQLiteStore.html \
		OpenID/Auth_OpenID_SRegBase.html \
		OpenID/Auth_OpenID_SRegRequest.html \
		OpenID/Auth_OpenID_SRegResponse.html \
		OpenID/Auth_OpenID_Server.html \
		OpenID/Auth_OpenID_ServerError.html \
		OpenID/Auth_OpenID_ServerErrorContainer.html \
		OpenID/Auth_OpenID_ServerRequest.html \
		OpenID/Auth_OpenID_ServerResponse.html \
		OpenID/Auth_OpenID_ServiceEndpointLoader.html \
		OpenID/Auth_OpenID_SessionNegotiator.html \
		OpenID/Auth_OpenID_SetupNeededResponse.html \
		OpenID/Auth_OpenID_Signatory.html \
		OpenID/Auth_OpenID_SigningEncoder.html \
		OpenID/Auth_OpenID_SuccessResponse.html \
		OpenID/Auth_OpenID_TypeURIMismatch.html \
		OpenID/Auth_OpenID_UntrustedReturnURL.html \
		OpenID/Auth_OpenID_WebResponse.html \
		OpenID/Auth_Yadis_Discovery.html \
		OpenID/Auth_Yadis_DiscoveryResult.html \
		OpenID/Auth_Yadis_Manager.html \
		OpenID/Auth_Yadis_ManagerLoader.html \
		OpenID/Auth_Yadis_PHPSession.html \
		OpenID/Auth_Yadis_Service.html \
		OpenID/Auth_Yadis_SessionLoader.html \
		OpenID/Auth_Yadis_XMLParser.html \
		OpenID/Auth_Yadis_XRDS.html \
		OpenID/Auth_Yadis_Yadis.html \
		OpenID/Auth_Yadis_dom.html \
		OpenID/Auth_Yadis_domxml.html \
		OpenID/_Auth---OpenID---AX.php.html \
		OpenID/_Auth---OpenID---Association.php.html \
		OpenID/_Auth---OpenID---Consumer.php.html \
		OpenID/_Auth---OpenID---DatabaseConnection.php.html \
		OpenID/_Auth---OpenID---DumbStore.php.html \
		OpenID/_Auth---OpenID---Extension.php.html \
		OpenID/_Auth---OpenID---FileStore.php.html \
		OpenID/_Auth---OpenID---Interface.php.html \
		OpenID/_Auth---OpenID---MemcachedStore.php.html \
		OpenID/_Auth---OpenID---Message.php.html \
		OpenID/_Auth---OpenID---MySQLStore.php.html \
		OpenID/_Auth---OpenID---Nonce.php.html \
		OpenID/_Auth---OpenID---PAPE.php.html \
		OpenID/_Auth---OpenID---PostgreSQLStore.php.html \
		OpenID/_Auth---OpenID---SQLStore.php.html \
		OpenID/_Auth---OpenID---SQLiteStore.php.html \
		OpenID/_Auth---OpenID---SReg.php.html \
		OpenID/_Auth---OpenID---Server.php.html \
		OpenID/_Auth---OpenID---ServerRequest.php.html \
		OpenID/_Auth---OpenID.php.html \
		OpenID/_Auth---Yadis---Manager.php.html \
		OpenID/_Auth---Yadis---XML.php.html \
		OpenID/_Auth---Yadis---XRDS.php.html \
		OpenID/_Auth---Yadis---Yadis.php.html \
		OpenID/tutorial_OpenID.pkg.html \
		classtrees_OpenID.html elementindex.html \
		elementindex_OpenID.html errors.html index.html \
		li_OpenID.html packages.html \
		media/banner.css media/stylesheet.css

EXAMPLES=	README consumer/common.php consumer/finish_auth.php \
		consumer/index.php consumer/try_auth.php detect.php \
		discover.php server/index.php server/lib/actions.php \
		server/lib/common.php server/lib/render.php \
		server/lib/render/about.php server/lib/render/idpXrds.php \
		server/lib/render/idpage.php server/lib/render/login.php \
		server/lib/render/trust.php server/lib/render/userXrds.php \
		server/lib/session.php server/openid-server.css \
		server/server.php server/setup.php

_DOCSDIR=	doc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
EXTRACT_SUFX=	.tar.bz2

.ifdef(WITH_BCMATH)
USE_PHP+=	bcmath
.else
USE_PHP+=	gmp
.endif

.ifdef(WITH_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

post-configure:
	@cd ${WRKSRC}/admin && ${PYTHON_CMD} packagexml.py ${PORTVERSION} package2.xml ../CHANGELOG > ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
