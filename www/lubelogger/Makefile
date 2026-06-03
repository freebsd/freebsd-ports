PORTNAME=	lubelogger
DISTVERSIONPREFIX=v
DISTVERSION=	1.5.9
CATEGORIES=	www

MAINTAINER=	ports@53hor.net
COMMENT=	Web-based vehicle maintenance and fuel mileage tracker
WWW=		https://lubelogger.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dotnet8>0:lang/dotnet8
LIB_DEPENDS=	libunwind.so:devel/libunwind

USES=		gssapi:mit inotify ssl:run

USE_GITHUB=	yes
GH_ACCOUNT=	hargata
GH_PROJECT=	lubelog

USE_RC_SUBR=	lubelogger

USERS=		lubelogger
GROUPS=		lubelogger

NUGET_GROUPS=	NUGET
NUGET_NUPKGS=	BouncyCastle.Cryptography:2.6.1 \
		CsvHelper:33.1.0 \
		LiteDB:5.0.17 \
		MailKit:4.14.1 \
		Microsoft.Extensions.DependencyInjection.Abstractions:8.0.2 \
		Microsoft.Extensions.Logging.Abstractions:8.0.2 \
		Microsoft.IdentityModel.Abstractions:8.15.0 \
		Microsoft.IdentityModel.JsonWebTokens:8.15.0 \
		Microsoft.IdentityModel.Logging:8.15.0 \
		Microsoft.IdentityModel.Tokens:8.15.0 \
		MimeKit:4.14.0 \
		Npgsql:9.0.4 \
		System.Formats.Asn1:8.0.1 \
		System.Security.Cryptography.Pkcs:8.0.1

DOTNET_CMD=	${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/dotnet

post-patch:
	${REINPLACE_CMD} -e 's|%%NUGET_DISTDIR%%|${DISTDIR}/${NUGET_DISTSUBDIR}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/nuget.config

do-build:
	cd ${WRKSRC} && \
		${DOTNET_CMD} restore CarCareTracker.csproj \
			--packages ${WRKDIR}/packages
	cd ${WRKSRC} && \
		${DOTNET_CMD} publish CarCareTracker.csproj \
			--packages ${WRKDIR}/packages \
			--configuration Release \
			--self-contained \
			-o bin/publish "-p:DebugSymbols=false;DebugType=none;UseAppHost=true;PublishReadyToRun=false"

do-install:
	cd ${WRKSRC}/bin/publish/ && ${ELFCTL} -e +noaslr ./CarCareTracker
	cd ${WRKSRC}/bin/publish/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/publish/CarCareTracker ${STAGEDIR}/${DATADIR}/
	${INSTALL_LIB} ${WRKSRC}/bin/publish/*.so ${STAGEDIR}/${DATADIR}/

.include "nuget.mk"
.include <bsd.port.mk>
