# New ports collection makefile for:	pRuby
# Date created:		24 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pruby
PORTVERSION=	0.20
CATEGORIES=	www lang ruby
MASTER_SITES=	http://www.inf.bme.hu/~pts/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	php:${PHP4_PORTDIR} \
		${LOCALBASE}/libexec/apache/libphp4.so:${MOD_PHP4_PORTDIR} \
		${NONEXISTENT}:${MOD_PHP4_PORTDIR}:configure
.if defined(PACKAGE_BUILDING)
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif
RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${MOD_PHP4_PORTDIR}

USE_GMAKE=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

PHP4_PORTDIR=		${.CURDIR}/../../lang/php4
MOD_PHP4_PORTDIR=	${.CURDIR}/../mod_php4
MOD_PHP4_WRKSRC_CMD=	cd ${MOD_PHP4_PORTDIR} && ${MAKE} -V WRKSRC

DOCS_EN=	README	contrib/_htaccess

pre-everything::
	dir=`${MOD_PHP4_WRKSRC_CMD}`; \
	${MKDIR} $${dir}; \
	${TOUCH} $${dir}/../../Makefile.inc

do-configure:
	cd ${WRKSRC} && ( \
		dir=`${MOD_PHP4_WRKSRC_CMD}`; \
		php contrib/phpinfo.php > phpinfo.out; \
		( \
		${ECHO} "PHP4_SRC=$${dir}"; \
		${ECHO} "PHP4_CONFIGURED=yes"; \
		${ECHO} "RUBY_SRC="; \
		${ECHO} "RUBY=${RUBY}"; \
		${ECHO} "PHPINFO_OUT=phpinfo.out"; \
		${ECHO} "LIBRUBYS_SO=${LOCALBASE}/lib/libruby.so"; \
		) > Configuration; \
	)

pre-install:
	dir=`. ${WRKSRC}/phpinfo.sd; ${ECHO} $${PI_EXTENSION_DIR}`; \
	${MKDIR} $${dir}

post-install:
	dir=`. ${WRKSRC}/phpinfo.sd; ${ECHO} $${PI_EXTENSION_DIR}`; \
	${INSTALL_DATA} ${WRKSRC}/ext_pruby_src/pruby_*.rb $${dir}/; \
	${PERL} -i -pe "s,%%EXTENSION_DIR%%,$${dir#${PREFIX}/},g" ${TMPPLIST}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.post.mk>
