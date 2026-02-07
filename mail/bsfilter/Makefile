PORTNAME=	bsfilter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.20
CATEGORIES=	mail ruby

MAINTAINER=	nyan@FreeBSD.org
COMMENT=	Bayesian spam filter written in Ruby
WWW=		https://github.com/nbkenichi/bsfilter

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-gdbm>=2.0.0,2:databases/rubygem-gdbm \
		rubygem-sdbm>=1.0.0:databases/rubygem-sdbm

USES=		ruby shebangfix
SHEBANG_FILES=	src/bsfilter.rb

USE_GITHUB=	yes
GH_ACCOUNT=	nbkenichi

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/bsfilter.rb ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for FILE in bsfilter.conf.sample dot-qmail.sample
	${INSTALL_DATA} ${FILESDIR}/${FILE} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for DIR in mda mua
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
