# Created by: Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
# $FreeBSD$

PORTNAME=	dovecot-sieve
PORTVERSION=	${DOVECOTVERSION}+${SIEVEVERSION}
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://pigeonhole.dovecot.org/releases/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${DISTVERSIONPREFIX}${SIEVEVERSION:C/:(.)/\1/g}${DISTVERSIONSUFFIX}

MAINTAINER=	yds@CoolRat.org
COMMENT=	Sieve plugin for the Dovecot 'deliver' LDA

LICENSE=	LGPL21

BUILD_DEPENDS=	${NONEXISTENT}:mail/dovecot:build
RUN_DEPENDS=	dovecot>=${DOVECOTVERSION}.*:mail/dovecot

DEPRECATED=	Dovecot-1.x is deprecated. Use dovecot2 and dovecot-pigeonhole instead
EXPIRATION_DATE=2017-07-31

DOVECOTVERSION=	1.2
SIEVEVERSION=	0.1.19

USES=		libtool:keepla
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docdir=${DOCSDIR} \
		--with-dovecot=`${MAKE} -C ${PORTSDIR}/mail/dovecot -V WRKSRC`
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot/lda

SUB_FILES=	pkg-message

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-/\//}

PORTDOCS=	AUTHORS COPYING COPYING.LGPL INSTALL NEWS README TODO spamtest-virustest.txt

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dovecot/lda/lib90_sieve_plugin.so

.include <bsd.port.mk>
