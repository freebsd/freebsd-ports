# New ports collection makefile for:	procmail
# Date created:		24 September 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	procmail
PORTVERSION=    3.22
PORTREVISION=   4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.procmail.org/pub/procmail/ \
		ftp://ftp.psg.com/pub/unix/procmail/ \
		ftp://ftp.ucsb.edu/pub/mirrors/procmail/ \
		ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/procmail/ \
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/procmail/ \
		ftp://ftp.fdt.net/pub/unix/packages/procmail/ \
		ftp://ftp.tamu.edu/pub/mirrors/procmail/ \
		ftp://ftp.kfki.hu/pub/packages/mail/procmail/ \
		ftp://giswitch.sggw.waw.pl/pub/unix/procmail/ \
		ftp://ftp.solarisguide.com/pub/procmail/ \
		ftp://ftp.win.ne.jp/pub/network/mail/procmail/ \
		http://www.ring.gr.jp/archives/net/mail/procmail/ \
		ftp://ftp.ring.gr.jp/pub/net/mail/procmail/ \
		ftp://ftp.ayamura.org/pub/procmail/ \
		ftp://sunsite.cnlab-switch.ch/mirror/procmail/ \
		ftp://ftp.gigabell.net/pub/procmail/ \
		ftp://ftp.linja.net/pub/mirrors/procmail/ \
		ftp://ftp.stealth.net/pub/mirrors/ftp.procmail.org/pub/procmail/ \
		ftp://ftp.mirrorservice.org/sites/ftp.procmail.org/pub/procmail/

MAINTAINER=	ache@FreeBSD.org
COMMENT=	A local mail delivery agent

# Global variables
#

USE_REINPLACE=	yes

# It asks for list of directories to do test for file locking
# (defaults to /tmp and ".", so return should suffice in most cases).
.if !defined(BATCH) # handled in patch-aa
IS_INTERACTIVE=	yes
.endif

INSTALL_TARGET=	install-suid install.man

MAN1=		procmail.1 formail.1 lockfile.1
MAN5=		procmailex.5 procmailrc.5 procmailsc.5

# Local variables
#

DOC_FILES=	FAQ FEATURES HISTORY KNOWN_BUGS README

SAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}
SAMPLE_FILES=	1procmailrc 1rmail 2procmailrc 2rmail 3procmailrc 3rmail \
		advanced dirname forward local_procmail_lmtp.m4 mailstat

# Post-configure
#

post-configure: patch-config

patch-config:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/config.h

# Post-install
#

post-install: install-sample install-doc

install-sample:
	@${MKDIR} ${SAMPLESDIR}
.for file in ${SAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${file} ${SAMPLESDIR}
.endfor

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
