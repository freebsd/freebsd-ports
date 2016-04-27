# Created by: Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
# $FreeBSD$

PORTNAME=	dovecot-pigeonhole
PORTVERSION=	0.4.14
CATEGORIES=	mail
MASTER_SITES=	http://pigeonhole.dovecot.org/releases/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${PORTVERSION}

MAINTAINER=	ler@lerctr.org
COMMENT=	Sieve plugin for the Dovecot 'deliver' LDA and LMTP

LICENSE=	LGPL21

BUILD_DEPENDS:=	dovecot2>=${DOVECOTVERSION}:mail/dovecot2
RUN_DEPENDS:=	dovecot2>=${DOVECOTVERSION}:mail/dovecot2

DOVECOTVERSION=	2.2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--without-dovecot-install-dirs \
		--docdir=${DOCSDIR} \
		--with-dovecot="${LOCALBASE}/lib/dovecot"
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	${PREFIX}/lib/dovecot
USE_OPENSSL=	yes

OPTIONS_DEFINE=	DOCS MANAGESIEVE
OPTIONS_DEFAULT=MANAGESIEVE
OPTIONS_SUB=	yes

MANAGESIEVE_DESC=		ManageSieve support
MANAGESIEVE_CONFIGURE_WITH=	managesieve

PORTDOCS=	sieve/extensions/* sieve/plugins/* sieve/locations/*

post-patch:
	@${REINPLACE_CMD} -E '\
	s!^(install-data-am:) install-sieve_docDATA!\1!; \
		s!^(uninstall-am:) uninstall-sieve_docDATA!\1!;' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
