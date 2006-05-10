# New ports collection makefile for:	scmail
# Date created:				13 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	scmail
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://namazu.org/~satoru/scmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mail filter written in Scheme

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${LOCALBASE}/share/gauche/${GAUCHE_VER}/lib/dbm/gdbm.scm:${PORTSDIR}/databases/gauche-gdbm

MAKE_ARGS=	PREFIX="${PREFIX}" DATADIR="${EXAMPLESDIR}"

PORTDOCS=	scbayes-ja.html scbayes.html scmail-ja.html scmail.html

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.if exists(${LOCALBASE}/bin/gauche-config)
GAUCHE_VER!=	${LOCALBASE}/bin/gauche-config -V
.else
GAUCHE_VER=	none
.endif

post-patch:
	${REINPLACE_CMD} -E -e "s,cp -f?p,${CP},g;s,/dot.scmail,," \
		${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/scmail/bayesian-filter.scm.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

# Maintainer only; it actually forwards mails to @examples.com!
test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.post.mk>
