# New ports collection makefile for:	logsurfer
# Date created:		28 Jul 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	logsurfer
PORTVERSION=	1.5b
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/audit/logsurfer/%SUBDIR%/ \
		ftp://ftp.tuwien.ac.at/infosys/security/dfn/tools/audit/logsurfer/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Process logfiles and conditionally perform certain actions

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etc-dir=${PREFIX}/etc

MAN1=		logsurfer.1
MAN4=		logsurfer.conf.4

post-install:
	@${MKDIR} ${PREFIX}/share/examples/logsurfer
	${INSTALL_DATA} ${WRKSRC}/config-examples/README \
		${PREFIX}/share/examples/logsurfer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
