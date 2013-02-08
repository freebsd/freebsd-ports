# Created by: Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
# $FreeBSD$

PORTNAME=	dovecot-pigeonhole
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.rename-it.nl/dovecot/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${PORTVERSION}

MAINTAINER=	bra@fsn.hu
COMMENT=	Sieve plugin for the Dovecot 'deliver' LDA and LMTP

LICENSE=	LGPL21

BUILD_DEPENDS:=	dovecot>=${DOVECOTVERSION}:${PORTSDIR}/mail/dovecot${DOVECOTVERSION:R}
RUN_DEPENDS:=	dovecot>=${DOVECOTVERSION}:${PORTSDIR}/mail/dovecot${DOVECOTVERSION:R}

DOVECOTVERSION=	2.1

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docdir=${DOCSDIR} \
		--with-dovecot="${LOCALBASE}/lib/dovecot"
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot

MAN1=		sieve-dump.1 sieve-filter.1 sieve-test.1 sievec.1 sieved.1
MAN7=		pigeonhole.7

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-/\//}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
EXTENSIONDOCS=	editheader.txt include.txt spamtest-virustest.txt \
		vacation.txt vnd.dovecot.duplicate.txt
PORTDOCS=	AUTHORS COPYING COPYING.LGPL INSTALL NEWS README TODO \
		script-location-dict.txt ${EXTENSIONDOCS}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME:S/-/\//}
PORTEXAMPLES=	*.sieve
.endif

post-patch:
	@${REINPLACE_CMD} -E '\
		s!^(install-data-am:) install-sieve_docDATA!\1!; \
		s!^(uninstall-am:) uninstall-sieve_docDATA!\1!;' \
		${WRKSRC}/doc/Makefile.in
.if ${PORT_OPTIONS:MDOCS}
.for f in ${EXTENSIONDOCS}
	@${LN} -f ${WRKSRC}/doc/extensions/${f} ${WRKSRC}/
.endfor
	@${LN} -f ${WRKSRC}/doc/script-location-dict.txt ${WRKSRC}/
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} ${_SHROWNGRP} -m ${BINMODE} -d ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}"
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${INSTALL} ${_SHROWNGRP} -m ${BINMODE} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.sieve ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}"
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
