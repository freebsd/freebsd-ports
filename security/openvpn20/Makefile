# New ports collection makefile for:	openvpn
# Date created:		2002-06-23
# Whom:			Matthias Andree <matthias.andree@web.de>
#
# $FreeBSD$
#

PORTNAME=	openvpn
PORTVERSION=	1.3.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	matthias.andree@web.de

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-lzo-lib=${LOCALBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--program-transform-name="s/x/x/"

MAN8=		openvpn.8

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/openvpn.sh.sample \
		${PREFIX}/etc/rc.d/openvpn.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in AUTHORS COPYING COPYRIGHT.GPL ChangeLog INSTALL NEWS \
	PORTS README
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.for dirs in easy-rsa sample-config-files sample-scripts
	@${MKDIR} ${DOCSDIR}/${dirs}
	@${INSTALL_DATA} ${WRKSRC}/${dirs}/* ${DOCSDIR}/${dirs}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
