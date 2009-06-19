# ex:ts=8
# Ports collection makefile for:	rdup
# Date created:			Jun 11, 2009
# Whom:				corky1951@comcast.net
#
# $FreeBSD$
#

PORTNAME=		rdup
PORTVERSION=	1.0.0
CATEGORIES=		sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
				http://miek.nl/projects/rdup/

MAINTAINER=	corky1951@comcast.net
COMMENT=	A tool to generate an (incremental) backup file list

LIB_DEPENDS=	glib-2.0:${PORTSDIR}/devel/glib20 \
				pcre:${PORTSDIR}/devel/pcre \
				archive:${PORTSDIR}/archivers/libarchive \
				nettle:${PORTSDIR}/security/nettle

USE_BZIP2=		yes

GNU_CONFIGURE=	yes

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/rdup \
		bin/rdup-tr \
		bin/rdup-up

MAN1=		rdup.1 \
		rdup-tr.1 \
		rdup-up.1

MAN7=		rdup-backups.7

.ifndef(NOPORTEXAMPLES)
PORTEXAMPLES=	rdup-ln.sh \
		rdup-simple.sh
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/rdup|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/rdup-backups.7

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for example in ${PORTEXAMPLES}
	@${INSTALL_SCRIPT} ${WRKSRC}/sh/${example} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
