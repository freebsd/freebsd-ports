# New ports collection makefile for: pgp4pine
# Date created:		29 February 2000
# Whom:			Holger Lamm <holger@flatline.de>
#
# $FreeBSD$
#

PORTNAME=	pgp4pine
PORTVERSION=	1.76
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://pgp4pine.flatline.de/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	holger@e-gitt.net
COMMENT=	Tool to use PGP 2/5/6 or GPG with Pine

# Global variables
#

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-docdir=${PREFIX}/share/doc
USE_REINPLACE=	yes

MAN1=		pgp4pine.1

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

# Local variables
#

SAMPLEDIR=	${PREFIX}/share/examples/${PORTNAME}
SCRIPTDIR=	${SAMPLEDIR}

.include <bsd.port.pre.mk>

# Post-patch
#

post-patch: patch-path patch-pkgmessage

patch-path:
	@${REINPLACE_CMD} \
		's|/usr/local|${PREFIX}|g;s|/doc/|/share/examples/|g' \
		${WRKSRC}/INSTALL \
		${WRKSRC}/insert_entries.pl ${WRKSRC}/remove_entries.pl

patch-pkgmessage:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}

# Post-configure
#

post-configure: patch-man

patch-man:
	@${REINPLACE_CMD} -e 's|/doc/|/examples/|g' \
		${WRKSRC}/pgp4pine/docs/en/pgp4pine.1

# Post-install
#

post-install: install-sample install-script uninstall-doc display-message

install-sample:
	@${MKDIR} ${SAMPLEDIR}
	@${MV} ${DOCSDIR}/pgp4pinerc.example ${SAMPLEDIR}

install-script:
	@${MKDIR} ${SCRIPTDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/insert_entries.pl \
			   ${WRKSRC}/remove_entries.pl ${SCRIPTDIR}

uninstall-doc:
.if defined(NOPORTDOCS)
	@${RM} -rf ${DOCSDIR}
.endif

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
