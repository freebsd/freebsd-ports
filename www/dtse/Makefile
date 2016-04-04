# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	dtse
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Indexing search engine for use on small websites

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_check_gnu_make.m4:devel/autoconf-archive

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

USES=		gmake perl5 shebangfix tar:bzip2
SHEBANG_FILES=	search.cgi.in
perl_OLD_CMD=	@which_perl@
USE_AUTOTOOLS=	aclocal:env automake:env autoconf:env

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/${PORTNAME}

MAKEFILE=	GNUmakefile

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_JOBS_UNSAFE=	yes

pre-configure:
	cd ${WRKSRC}; ${SH} autogen.sh

.include <bsd.port.mk>
