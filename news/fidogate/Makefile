# New ports collection makefile for:    fidogate
# Date created:         02 Dez 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	fidogate
PORTVERSION=	4.4.10
CATEGORIES=	news mail
MASTER_SITES=	ftp://ftp.fidogate.org/pub/fidogate/ \
		ftp://ftp.fu-berlin.de/unix/news/fidogate/ \
		http://www.fidogate.org/pub/fidogate/
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Fido-Internet Gateway and Tosser

# you may commet out this line if you have another transfer-agent
RUN_DEPENDS=	${LOCALBASE}/libexec/ifmail/ifcico:${PORTSDIR}/news/ifmail

.if defined(PARALLEL_PACKAGE_BUILD)
IGNORE=	indefinite hang
.endif

USE_GMAKE=	yes
USE_PERL5=	yes

DOCLIST=	fidogate.texi fidogate.txt gatebau94.txt kludge-rfc.doc \
		msgid.doc qmail.txt texinfo.tex dirs.html index.html \
		template.html fido howto misc rfc gatebau/msgid.sgml \
		gatebau/msgid.tex gatebau/msgid.txt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-perl
.endif

pre-configure:
	@${PERL5} -pi -e "s=.{PREFIX}=${PREFIX}=g" ${WRKSRC}/config.make
.if defined(FIDOGATE_RUNAS)
	@${PERL5} -pi -e "s/OWNER.*= news/OWNER		= ${FIDOGATE_RUNAS}/" \
		${WRKSRC}/config.make
.endif

pre-install:
	${MKDIR} ${PREFIX}/libexec/fidogate
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html ${DOCSDIR}/info ${DOCSDIR}/fido \
		${DOCSDIR}/howto ${DOCSDIR}/misc ${DOCSDIR}/gatebau
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKSRC}/doc -cf - ${DOCLIST} | ${TAR} -C ${DOCSDIR} -xf -
	${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/examples -cf - . | ${TAR} -C ${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.post.mk>
