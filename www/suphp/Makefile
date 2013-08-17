# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	suphp
PORTVERSION=	0.7.2
CATEGORIES=	www
MASTER_SITES=	http://www.suphp.org/download/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|koitsu|}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Securely execute PHP scripts under Apache

DEPRECATED=	Upstream dead, EOL: https://lists.marsching.com/pipermail/suphp/2013-May/002554.html
EXPIRATION_DATE=2013-12-17

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:env automake autoconf:env libtool:env
AUTOMAKE_ARGS+=	--add-missing

# Maintainer has not tested suPHP 0.6.x on Apache 1.3.
USE_APACHE=	22
CFLAGS+=	-I${LOCALBASE}/include
USE_CSTD=	gnu89
USE_PHP=	yes
WANT_PHP_CGI=	yes

MYPORTDOCS=	apache/CONFIG apache/INSTALL apache/README CONFIG LICENSE INSTALL README

CONFIGURE_ARGS=	CFLAGS="${CFLAGS}" --with-apxs=${APXS}

# WITH_SETID_MODE should be a value of "owner", "force", or "paranoid".
# It's important that you understand the differences between each mode.
# See /usr/local/share/doc/suphp/INSTALL for details.
#
WITH_SETID_MODE?=	owner
CONFIGURE_ARGS+=	--with-setid-mode=${WITH_SETID_MODE}

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|2.68|%%AUTOCONF_VERSION%%|g' \
			  -e 's|1.11.3|%%AUTOMAKE_VERSION%%|g' \
			  ${WRKSRC}/aclocal.m4

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/apache
.for f in ${MYPORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/${f}
.endfor
.endif
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${PREFIX}/sbin/suphp
.endif
	@${INSTALL_DATA} ${WRKSRC}/doc/suphp.conf-example ${PREFIX}/etc/suphp.conf-example
	@${APXS} -e -a -n "${SHORTMODNAME}" "${APACHEMODDIR}/mod_${MODULENAME}.so"
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
