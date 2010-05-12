# New ports collection makefile for:	suphp
# Date created:		15 September 2002
# Whom:			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	suphp
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.suphp.org/download/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|koitsu|}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	Securely execute PHP scripts under Apache

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:110:env automake:110:env autoconf:262:env libtool:22:env

# Maintainer has not tested suPHP 0.6.x on Apache 1.3.
USE_APACHE=	2.0+
USE_PHP=	yes
WANT_PHP_CGI=	yes

MYPORTDOCS=	apache/CONFIG apache/INSTALL apache/README CONFIG LICENSE INSTALL README

CONFIGURE_ARGS=	CFLAGS=-I${LOCALBASE}/include --with-apxs=${APXS}

# WITH_SETID_MODE should be a value of "owner", "force", or "paranoid".
# It's important that you understand the differences between each mode.
# See /usr/local/share/doc/suphp/INSTALL for details.
#
WITH_SETID_MODE?=	owner
CONFIGURE_ARGS+=	--with-setid-mode=${WITH_SETID_MODE}

.include <bsd.port.pre.mk>

# Apache 2.0 (www/apache2) has apr-config in LOCALBASE/lib/apache2, while
# Apache 2.2 (www/apache22) has apr-1-config in LOCALBASE/bin.
#
.if ${APACHE_VERSION} == 20
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}/lib/apache2
.else
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4
	@${CHMOD} 755 ${WRKSRC}/config/install-sh

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
