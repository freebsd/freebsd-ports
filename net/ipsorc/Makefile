# New ports collection makefile for:    ipsorc
# Date created:                         02 December, 2001
# Whom:                                 Nicolas.Jombart@hsc-labs.com
#
# $FreeBSD$
#

PORTNAME=	ipsorc
PORTVERSION=	1.7.5
CATEGORIES=	net security
MASTER_SITES=	http://www.informony.com/ipsorc/
#MASTER_SITE_SUBDIR=     ${PORTNAME}

MAINTAINER=	Nicolas.Jombart@hsc-labs.com

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_BZIP2=	yes

post-patch:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	@${SED} s,gtk-config,${GTK_CONFIG}, < ${WRKSRC}/Makefile.old \
	        > ${WRKSRC}/Makefile
	@${RM} ${WRKSRC}/Makefile.old

do-install:
.for file in ipmagic magic
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README HOWTO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
