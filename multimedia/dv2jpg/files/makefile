
INC=`${GDK_PIXBUF_CONFIG} --cflags` -I${PREFIX}/include/libdv
LIBS=-ljpeg -lm -ldv `${GDK_PIXBUF_CONFIG} --libs` -L${LOCALBASE}/lib

# what type of video do you want?
VIDEO=NTSC
# VIDEO=PAL

all: dv2jpg avijoin
	
dv2jpg: dv2jpg.o avilib.o dvavilib.o
	$(CC) $(CFLAGS) -o dv2jpg dv2jpg.o avilib.o dvavilib.o $(LIBS) $(LDFLAGS)

dv2jpg.o: dv2jpg.c
	$(CC) $(CFLAGS) $(INC) -D$(VIDEO) -c dv2jpg.c

avilib.o: avilib.c
	$(CC) $(CFLAGS) -c avilib.c

dvavilib.o: dvavilib.c
	$(CC) $(CFLAGS) -c dvavilib.c

clean: 
	/bin/rm -f *.o dv2jpg core avijoin

avijoin: avijoin.c avilib.o
	$(CC) $(CFLAGS) -o avijoin avijoin.c avilib.o $(LDFLAGS)
