Fix linker error when FLTK option is enabled.

ld: error: duplicate symbol: foodwork
>>> defined at anameal.c
>>>            ../anameal.o:(foodwork)
>>> defined at PersonalOptions.cc
>>>            PersonalOptions.o:(.bss+0x0)

--- anameal.c.orig	2023-08-21 10:50:52 UTC
+++ anameal.c
@@ -29,7 +29,7 @@
 #include <strings.h>
 #include <time.h>
 
-struct food *foodwork;
+struct food *foodwork_cli;
 int max;
 
 void analyze_meals(struct meal *meal_ptr_origin, int specialheader)
@@ -43,7 +43,7 @@ float prodefic, thispct, totaldefic, serving_ratio;
 float deficpct[DV_COUNT], food_abacus[MAX_FOOD], serving_ratio_abacus[MAX_FOOD];
 int deficnut[DV_COUNT];
 float prodefic, thispct, totaldefic, serving_ratio;
-foodwork = &food_work;
+foodwork_cli = &food_work;
 options.temp_meal_root = meal_ptr_origin;
 mealcount = meal_count(meal_ptr_origin);
 max = mealcount;
