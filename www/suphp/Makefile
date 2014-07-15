# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	suphp
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.suphp.org/download/ \
		LOCAL/bdrewery/${PORTNAME}/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Securely execute PHP scripts under Apache

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:env automake autoconf:env libtool:env
AUTOMAKE_ARGS+=	--add-missing
SUB_FILES=	pkg-message

USE_APACHE=	22
CFLAGS+=	-I${LOCALBASE}/include
USE_CSTD=	gnu89
USE_PHP=	yes
WANT_PHP_CGI=	yes

MYPORTDOCS=	apache/CONFIG \
		apache/INSTALL \
		apache/README \
		CONFIG LICENSE \
		INSTALL README

CONFIGURE_ARGS=	CFLAGS="${CFLAGS}" --with-apxs=${APXS}

# WITH_SETID_MODE should be a value of "owner", "force", or "paranoid".
# It's important that you understand the differences between each mode.
# See /usr/local/share/doc/suphp/INSTALL for details.
#
WITH_SETID_MODE?=	owner
CONFIGURE_ARGS+=	--with-setid-mode=${WITH_SETID_MODE}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|2.68|%%AUTOCONF_VERSION%%|g' \
			  -e 's|1.11.3|%%AUTOMAKE_VERSION%%|g' \
			  ${WRKSRC}/aclocal.m4

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apache
.for f in ${MYPORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor
.endif
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/suphp
.endif
	@${INSTALL_DATA} ${WRKSRC}/doc/suphp.conf-example \
	    ${STAGEDIR}${PREFIX}/etc/suphp.conf-example

.include <bsd.port.mk>
