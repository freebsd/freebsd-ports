# $FreeBSD$
#
PREFIX?=	/usr/local
BINDIR=		${PREFIX}/bin
MANDIR=		${PREFIX}/man/man
PROG_CXX=	spamprobe
SRCS=		File.cc FrequencyDB.cc LockFile.cc Message.cc \
		MessageFactory.cc MimeHeader.cc MimeLineReader.cc \
		MimeMessageReader.cc SpamFilter.cc spamprobe.cc util.cc

.include <bsd.prog.mk>
