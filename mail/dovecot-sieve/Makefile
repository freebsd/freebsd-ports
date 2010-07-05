# New ports collection makefile for:	dovecot-sieve
# Date created:		2006-12-29
# Whom:			Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot-sieve
PORTVERSION=	${DOVECOTVERSION}+${DISTVERSION}
DISTVERSION=	0.1.17
CATEGORIES=	mail
MASTER_SITES=	http://www.rename-it.nl/dovecot/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${DISTVERSIONPREFIX}${DISTVERSION:C/:(.)/\1/g}${DISTVERSIONSUFFIX}

MAINTAINER=	yds@CoolRat.org
COMMENT=	A Sieve plugin for the Dovecot 'deliver' LDA

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/mail/dovecot:build
RUN_DEPENDS=	dovecot>=${DOVECOTVERSION}.*:${PORTSDIR}/mail/dovecot

DOVECOTVERSION=	1.2

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docdir=${DOCSDIR} \
		--with-dovecot=`${MAKE} -C ${PORTSDIR}/mail/dovecot -V WRKSRC`
CONFIGURE_ENV=	LDFLAGS='${LDFLAGS}'
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot/lda

SUB_FILES=	pkg-message

MAN1=		sieve-test.1 sievec.1 sieved.1

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-/\//}

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING COPYING.LGPL INSTALL NEWS README TODO spamtest-virustest.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e '\
		s!/doc/$${PACKAGE_TARNAME}!/doc/${PORTNAME:S/-/\//}!g;\
		s!$${docdir}/dovecot/sieve!$${docdir}!g;\
		' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e '\
		/^docfiles = spamtest-virustest.txt$$/D;\
		/^[[:space:]]+test -z "\$$\(sieve_docdir\)" \|\| \$$\(MKDIR_P\) "\$$\(DESTDIR\)\$$\(sieve_docdir\)"$$/D;\
		' ${WRKSRC}/doc/Makefile.in
	@${LN} -f ${WRKSRC}/doc/spamtest-virustest.txt ${WRKSRC}/

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} ${_SHROWNGRP} -m ${BINMODE} -d ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
