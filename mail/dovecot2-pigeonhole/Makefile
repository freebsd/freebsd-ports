# Created by: Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
# $FreeBSD$

PORTNAME=	dovecot-pigeonhole
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.rename-it.nl/dovecot/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${PORTVERSION}

MAINTAINER=	bra@fsn.hu
COMMENT=	Sieve plugin for the Dovecot 'deliver' LDA and LMTP

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS:=	dovecot>=${DOVECOTVERSION}:${PORTSDIR}/mail/dovecot2
RUN_DEPENDS:=	dovecot>=${DOVECOTVERSION}:${PORTSDIR}/mail/dovecot2

DOVECOTVERSION=	2.2

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--without-dovecot-install-dirs \
		--docdir=${DOCSDIR} \
		--with-dovecot="${LOCALBASE}/lib/dovecot"
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot

MAN1=		sieve-dump.1 sieve-filter.1 sieve-test.1 sievec.1 sieved.1
MAN7=		pigeonhole.7
PORTDOCS=	doc/extensions/* doc/plugins/* doc/rfc/*

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E '\
	s!^(install-data-am:) install-sieve_docDATA!\1!; \
		s!^(uninstall-am:) uninstall-sieve_docDATA!\1!;' \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
