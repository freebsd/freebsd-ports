# New ports collection makefile for:	jabber
# Date created:			5 February 2001
# Whom:				joe
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://jabberd.jabberstudio.org/downloads/ \
		http://download.jabber.org/dists/1.4/final/
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Online presence and instant messaging server

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_PERL5=	yes

CONFIGURE_ARGS+=	--enable-ssl

rc=${PREFIX}/etc/rc.d

#JABDIR=		${PORTNAME}-${PORTVERSION}
# Save this data for use later: jabber doesn't have an install target
# or a sane set of defaults.
post-patch:
	@echo "${WRKSRC}" > ${WRKSRC}/.wrksrc-freebsd
	@echo "${PREFIX}" > ${WRKSRC}/.prefix-freebsd
	@echo "${INSTALL_DATA}" > ${WRKSRC}/.install_data-freebsd
	@echo "${INSTALL_SCRIPT}" > ${WRKSRC}/.install_script-freebsd
	@echo "${INSTALL_PROGRAM}" > ${WRKSRC}/.install_program-freebsd

post-install:
	@PREFIX=${PREFIX} ${PERL5} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${INSTALL_SCRIPT} ${FILESDIR}/jabberd.sh ${rc}

.include <bsd.port.mk>
