PORTNAME=	dtse
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	http://dl1.douglasthrift.net/${PORTNAME}/ \
		http://dl2.douglasthrift.net/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Indexing search engine for use on small websites

LICENSE=	APACHE11
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_check_gnu_make.m4:devel/autoconf-archive

USES=		autoreconf gmake perl5 shebangfix tar:bzip2
SHEBANG_FILES=	search.cgi.in
perl_OLD_CMD=	@which_perl@

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${PORTNAME}

MAKEFILE=	GNUmakefile

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		OPENSSL

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}

.include <bsd.port.mk>
