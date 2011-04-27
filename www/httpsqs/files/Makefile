# $FreeBSD$
# Makefile for httpsqs (pmake)

tokyocabinet_CFLAGS!=	pkg-config --cflags tokyocabinet
libevent_CFLAGS!=	pkg-config --cflags libevent
tokyocabinet_LIBS!=	pkg-config --libs tokyocabinet
libevent_LIBS!=	pkg-config --libs libevent
CFLAGS+=	${tokyocabinet_CFLAGS} ${libevent_CFLAGS}
LIBS+=	${tokyocabinet_LIBS} ${libevent_LIBS}

all: httpsqs

httpsqs: httpsqs.o prename.o
	${CC} ${LDFLAGS} ${LIBS} -o ${.TARGET} ${.ALLSRC}
httpsqs.o: httpsqs.c
prename.o: prename.c

install: httpsqs
