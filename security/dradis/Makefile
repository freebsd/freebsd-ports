# Created by: Dax Labrador <semprix@bsdmail.org>
# $FreeBSD$

PORTNAME=	dradis
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/v${PORTVERSION}

MAINTAINER=	semprix@gmx.com
COMMENT=	Opensource framework to enable effective information gathering

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems \
		${RUBY_SITELIBDIR}/wirble.rb:${PORTSDIR}/devel/ruby-wirble \
		rubygem-rake>=0.8.7:${PORTSDIR}/devel/rubygem-rake \
		rubygem-rails>=3.0.5:${PORTSDIR}/www/rubygem-rails \
		rubygem-activesupport>=3.0.2:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-bundler>=1.0.7:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-redcloth>=4.2.7:${PORTSDIR}/www/rubygem-redcloth \
		rubygem-sqlite3>=1.3.2:${PORTSDIR}/databases/rubygem-sqlite3

USE_RC_SUBR=	dradis
SUB_FILES=	pkg-message
SUB_LIST=	INSTDIR="${PREFIX}/${INSTDIR}" \
		RUBY_CMD=${RUBY_WITHOUT_SUFFIX}

INSTDIR?=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:R}

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
RUBY_SHEBANG_FILES=	server/script/rails server/script/delayed_job
RUBY_NO_BUILD_DEPENDS=	yes

USES=		dos2unix
DOS2UNIX_REGEX=	.*(css|rb|txt|js|RELEASE_NOTES)$$

pre-install:
	${FIND} ${WRKSRC}/server -type f \( -name "*.bak" -o -name "*.orig" -o -name "*.swp" \) -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	( cd ${WRKSRC} && ${COPYTREE_SHARE} server ${STAGEDIR}${PREFIX}/${PORTNAME}/ )

.include <bsd.port.mk>
