# New ports collection makefile for:    fidogate
# Date created:         02 Dez 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	fidogate
PORTVERSION=	4.4.9
PORTREVISION=	3
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

FIXME=		src/common/aliases.c src/common/binkley.c \
		src/common/config.c src/common/crc32.c \
		src/common/file.c src/common/flo.c \
		src/common/fopen.c src/common/hosts.c \
		src/common/lock.c src/common/log.c \
		src/common/mail.c src/common/message.c \
		src/common/outpkt.c src/common/packet.c \
		src/common/routing.c src/common/sequencer.c \
		src/common/tick.c src/charset/charset.c \
		src/areafix/ftnaf.c src/areafix/areafix.c \
		src/areafix/ftnafmail.c src/areafix/ftnafpkt.c \
		src/areafix/ftnafutil.c src/ffx/ffx.c \
		src/ffx/ffxqt.c src/gate/ftn2rfc.c \
		src/gate/ftnin.c src/gate/rfc2ftn.c \
		src/gate/ftnmail.c src/tick/ftnhatch.c \
		src/tick/ftntick.c src/toss/ftn2ftn.c \
		src/toss/ftnexpire.c src/toss/ftnpack.c \
		src/toss/ftnroute.c src/toss/ftntoss.c \
		src/toss/history.c src/util/ftnlog.c \
		src/util/ftnflo.c

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-perl
.endif

post-patch:
.for i in ${FIXME}
	${PERL5} -pi -e "s=([	 ])log[(]=\\1log_fg(=" ${WRKSRC}/${i}
	@${GREP} "log_fg" ${WRKSRC}/${i}
.endfor

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
