# New ports collection makefile for:    fidogate
# Version required:     fidogate-4.2.9
# Date created:         02 Dez 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.2 1998/12/24 13:03:50 flathill Exp $
#

DISTNAME=	fidogate-4.2.9
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.dinoex.sub.org/pub/approved/
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dirk.meyer@dinoex.sub.org

# you may commet out this line if you have another transfer-agent
RUN_DEPENDS=	${PREFIX}/libexec/ifmail/ifcico:${PORTSDIR}/news/ifmail

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/fidogate

pre-configure:
	@${MV} ${WRKSRC}/config.make ${WRKSRC}/config.make.sed
	@${SED} -e 's/\$${PREFIX}/${PREFIX:S/\//\\\//g}/g' \
		< ${WRKSRC}/config.make.sed > ${WRKSRC}/config.make

pre-install:
	${MKDIR} ${PREFIX}/libexec/fidogate
	${MKDIR} ${PREFIX}/share/doc/fidogate/html
	${MKDIR} ${PREFIX}/share/doc/fidogate/info
	${MKDIR} ${PREFIX}/share/doc/fidogate/fido
	${MKDIR} ${PREFIX}/share/doc/fidogate/howto
	${MKDIR} ${PREFIX}/share/doc/fidogate/misc
	${MKDIR} ${PREFIX}/share/doc/fidogate/gatebau

DOCLIST = \
	Fido-Point-HOWTO Fido-Point-eng-HOWTO \
	fidogate.texi fidogate.txt \
	gatebau94.txt kludge-rfc.doc msgid.doc \
	qmail.txt texinfo.tex \
	fido \
	howto \
	misc \
	rfc \
	gatebau/msgid.sgml \
	gatebau/msgid.tex \
	gatebau/msgid.txt

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fidogate
	@cd ${WRKSRC}/doc; tar cf - ${DOCLIST} |\
		(cd ${PREFIX}/share/doc/fidogate; tar xf -)
	${MKDIR} ${PREFIX}/share/examples/fidogate
	@cd ${WRKSRC}/examples; tar cf - . |\
		(cd ${PREFIX}/share/examples/fidogate; tar xf -)
.endif

.include <bsd.port.mk>
