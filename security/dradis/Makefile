# Created by: Dax Labrador <semprix@bsdmail.org>
# $FreeBSD$

PORTNAME=	dradis
DISTVERSION=	2.6.1
CATEGORIES=	security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME:L}/${PORTNAME:L}/v${PORTVERSION}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	semprix@gmx.com
COMMENT=	Opensource framework to enable effective information gathering

RUN_DEPENDS=	${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems \
		${RUBY_SITELIBDIR}/wirble.rb:${PORTSDIR}/devel/ruby-wirble \
		rubygem-rake>=0.8.7:${PORTSDIR}/devel/rubygem-rake \
		rubygem-rails>=3.0.5:${PORTSDIR}/www/rubygem-rails \
		rubygem-activesupport>=3.0.2:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-bundler>=1.0.7:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-redcloth>=4.2.7:${PORTSDIR}/www/rubygem-redcloth \
		rubygem-sqlite3>=1.3.2:${PORTSDIR}/databases/rubygem-sqlite3

LICENSE=	GPLv2

USE_RC_SUBR=	dradis
SUB_FILES=	pkg-message
SUB_LIST=	INSTDIR="${PREFIX}/${INSTDIR}" \
		RUBY_CMD=${RUBY_WITHOUT_SUFFIX}

INSTDIR?=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:R}

NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
RUBY_SHEBANG_FILES=	server/script/rails server/script/delayed_job
RUBY_NO_BUILD_DEPENDS=	yes

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*(css|rb|txt|js|RELEASE_NOTES)$$

NO_STAGE=	yes
pre-install:
	@${FIND} ${WRKSRC}/server -type f \( -name "*.bak" -o -name "*.orig" -o -name "*.swp" \) -delete

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@( cd ${WRKSRC} && ${COPYTREE_SHARE} server ${PREFIX}/${PORTNAME}/ )

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
