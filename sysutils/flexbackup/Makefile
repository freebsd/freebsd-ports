# New ports collection makefile for:    flexbackup
# Date created:         Wed Nov  3 17:58:26 MST 1999
# Whom:                 John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	flexbackup
PORTVERSION=	1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edwinh.org/flexbackup/tarball/ \
		http://www.reynoldsnet.org/flexbackup/tarball/

MAINTAINER=	johnjen@reynoldsnet.org
COMMENT=	A flexible backup tool (Perl)

MAKE_ARGS=	CONFFILE=${LOCALBASE}/etc/flexbackup.conf \
		PERLPATH=${PERL}

USE_PERL5=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fb.install ${LOCALBASE}/bin/flexbackup
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf ${LOCALBASE}/etc/flexbackup.conf.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in CHANGES COPYING CREDITS README TODO faq.html
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
