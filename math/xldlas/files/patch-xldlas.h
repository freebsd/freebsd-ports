--- xldlas.h.orig	1997-05-12 15:02:44 UTC
+++ xldlas.h
@@ -23,6 +23,11 @@
 #include <sys/wait.h>
 #include <assert.h>
 
+#ifdef IN_MAIN
+#define EXTERN
+#else
+#define EXTERN extern
+#endif
 
 /*
 	Some things you can only change at compile time
@@ -51,8 +56,10 @@
 	change the numbers above to suit your tastes (and recompile!).
 */
 
+#ifndef TRUE
 #define TRUE		1			/* Standard Logic Testing		*/
 #define	FALSE		0			/* "			"		*/
+#endif
 #define TYPE_COLS	1			/* User supplied format for imports	*/
 #define TYPE_ROWS	2			/* "				  "	*/
 #define	TINY		1.0e-20			/* Need this to calculate Gamma function*/
@@ -189,117 +196,114 @@ struct math_thingy
 		int	variable_lag;
 };
 
-	
-struct	vector_structure data_matrix[MAX_VARS];		/*Data Attributes */
-struct  math_thingy math_construct;			/* Math thingy 	  */
-float	*fvector[MAX_VARS];				/*The actual data */
-char	data_matrix_description[DESC_LENGTH];		/*What data is it?*/
-							/*Flags		  */
-float	ga_coefs[MAX_VARS][4];
-float	ga_powers[MAX_VARS][4];
+EXTERN struct	vector_structure data_matrix[MAX_VARS];		/*Data Attributes */
+EXTERN struct  math_thingy math_construct;			/* Math thingy 	  */
+EXTERN float	*fvector[MAX_VARS];				/*The actual data */
+EXTERN char	data_matrix_description[DESC_LENGTH];		/*What data is it?*/
 
+EXTERN float	ga_coefs[MAX_VARS][4];
+EXTERN float	ga_powers[MAX_VARS][4];
 
-int	oktoquit, data_exists, gen_exists;
-int	help_exists[11];
-int	quick_dropping;
-int	real_drop;
-int	log_on;
-int	texlog_on;
-int	htmllog_on;
-int	log_verbose_on;
-int	texlog_verbose_on;
-int	htmllog_verbose_on;
-int	anova_type;
-int	balloon_help;
-							/*Flags		  */
-int	numb_variables;					/*Vars in memory  */
+EXTERN int	oktoquit, data_exists, gen_exists;
+EXTERN int	help_exists[11];
+EXTERN int	quick_dropping;
+EXTERN int	real_drop;
+EXTERN int	log_on;
+EXTERN int	texlog_on;
+EXTERN int	htmllog_on;
+EXTERN int	log_verbose_on;
+EXTERN int	texlog_verbose_on;
+EXTERN int	htmllog_verbose_on;
+EXTERN int	anova_type;
+EXTERN int	balloon_help;
 
-int 	import_type;
-int	graph_window_open;
-int	assume_sample;
+EXTERN int	numb_variables;					/*Vars in memory  */
 
-char	help_location[XLDLASMAX_INPUT];		/*Where are help files?	  */
-FILE	*log_file;				/*File pointer for log    */
-FILE	*texlog_file;				/*File pointer for tex log*/
-FILE	*htmllog_file;				/*File pointer for htmllog*/
-char	log_name[XLDLASMAX_INPUT];
-char	texlog_name[XLDLASMAX_INPUT];
-char	htmllog_name[XLDLASMAX_INPUT];
-int     all_start;				/*Start obser for loops   */
-int     all_stop;				/*End obser for loops     */
-float	missing_value;				/*Value of missing obs	  */
-char	line_of_output[XLDLASMAX_INPUT];	/*Used to display results */
-char	filtered_tex_string[XLDLASMAX_INPUT];
-float	working[MAX_OBS];
-float	working_two[MAX_OBS];
-int	worksize;
-int	worksize_two;
-int	gnuplot_pipe;
-FILE	*gnuplot_datafile;
-char	gnuplot_datafile_name[L_tmpnam];
-pid_t	gnuplot_pid;
-int	graph_key_on;
-int	graph_overwrite_on;
-int	graph_normal_on;
-char	graph_output_format[XLDLASMAX_INPUT];
-char	graph_output_options[XLDLASMAX_INPUT];
-int	point_style[MAX_VARS];
-int	line_style[MAX_VARS];
-int	temp_varnumber;
-int	numb_bars;
-char	gnuplot_geometry[XLDLASMAX_INPUT];
-extern  char **environ;
-int	main_offset;
+EXTERN int 	import_type;
+EXTERN int	graph_window_open;
+EXTERN int	assume_sample;
 
-int ga_cycles;
-int nn_cycles;
-int nn_pictex;
-int nn_squash;
-int nn_hidden;
-int nn_annealing;
-float nn_learn;
-int ga_update;
-int ga_mutate;
-int ga_force;
-int ga_maxreal;
-int ga_bitsize;
-int ga_poolsize;
-int ga_swap;
-int ga_cross;
-int ga_perturbe;
-int ga_tolerance;
+EXTERN char	help_location[XLDLASMAX_INPUT];		/*Where are help files?	  */
+EXTERN FILE	*log_file;				/*File pointer for log    */
+EXTERN FILE	*texlog_file;				/*File pointer for tex log*/
+EXTERN FILE	*htmllog_file;				/*File pointer for htmllog*/
+EXTERN char	log_name[XLDLASMAX_INPUT];
+EXTERN char	texlog_name[XLDLASMAX_INPUT];
+EXTERN char	htmllog_name[XLDLASMAX_INPUT];
+EXTERN int     all_start;				/*Start obser for loops   */
+EXTERN int     all_stop;				/*End obser for loops     */
+EXTERN float	missing_value;				/*Value of missing obs	  */
+EXTERN char	line_of_output[XLDLASMAX_INPUT];	/*Used to display results */
+EXTERN char	filtered_tex_string[XLDLASMAX_INPUT];
+EXTERN float	working[MAX_OBS];
+EXTERN float	working_two[MAX_OBS];
+EXTERN int	worksize;
+EXTERN int	worksize_two;
+EXTERN int	gnuplot_pipe;
+EXTERN FILE	*gnuplot_datafile;
+EXTERN char	gnuplot_datafile_name[L_tmpnam];
+EXTERN pid_t	gnuplot_pid;
+EXTERN int	graph_key_on;
+EXTERN int	graph_overwrite_on;
+EXTERN int	graph_normal_on;
+EXTERN char	graph_output_format[XLDLASMAX_INPUT];
+EXTERN char	graph_output_options[XLDLASMAX_INPUT];
+EXTERN int	point_style[MAX_VARS];
+EXTERN int	line_style[MAX_VARS];
+EXTERN int	temp_varnumber;
+EXTERN int	numb_bars;
+EXTERN char	gnuplot_geometry[XLDLASMAX_INPUT];
+extern char	**environ;
+EXTERN int	main_offset;
 
-int ga_cross_ok;
-int ga_mutate_ok;
-int ga_perturbe_ok;
-int ga_force;
+EXTERN int ga_cycles;
+EXTERN int nn_cycles;
+EXTERN int nn_pictex;
+EXTERN int nn_squash;
+EXTERN int nn_hidden;
+EXTERN int nn_annealing;
+EXTERN float nn_learn;
+EXTERN int ga_update;
+EXTERN int ga_mutate;
+EXTERN int ga_force;
+EXTERN int ga_maxreal;
+EXTERN int ga_bitsize;
+EXTERN int ga_poolsize;
+EXTERN int ga_swap;
+EXTERN int ga_cross;
+EXTERN int ga_perturbe;
+EXTERN int ga_tolerance;
 
-int general_abort;
-int pearls_of_wisdom;
-int main_font;
+EXTERN int ga_cross_ok;
+EXTERN int ga_mutate_ok;
+EXTERN int ga_perturbe_ok;
+EXTERN int ga_force;
 
-char print_command[XLDLASMAX_INPUT];
-char tex_command[XLDLASMAX_INPUT];
-char dviview_command[XLDLASMAX_INPUT];
-char dviprint_command[XLDLASMAX_INPUT];
-char tex_preamble[XLDLASMAX_INPUT];
-char tex_graphmacrol[XLDLASMAX_INPUT];
-char tex_graphmacror[XLDLASMAX_INPUT];
+EXTERN int general_abort;
+EXTERN int pearls_of_wisdom;
+EXTERN int main_font;
 
+EXTERN char print_command[XLDLASMAX_INPUT];
+EXTERN char tex_command[XLDLASMAX_INPUT];
+EXTERN char dviview_command[XLDLASMAX_INPUT];
+EXTERN char dviprint_command[XLDLASMAX_INPUT];
+EXTERN char tex_preamble[XLDLASMAX_INPUT];
+EXTERN char tex_graphmacrol[XLDLASMAX_INPUT];
+EXTERN char tex_graphmacror[XLDLASMAX_INPUT];
 
 
-extern void file_routines(FL_OBJECT *menu, long user_data);
-extern void data_routines(FL_OBJECT *menu, long user_data);
-extern void log_routines(FL_OBJECT *menu, long user_data);
-extern void graph_routines(FL_OBJECT *menu, long user_data);
-extern void analysis_routines(FL_OBJECT *menu, long user_data);
-extern void help_routines(FL_OBJECT *menu, long user_data);
+EXTERN void file_routines(FL_OBJECT *menu, long user_data);
+EXTERN void data_routines(FL_OBJECT *menu, long user_data);
+EXTERN void log_routines(FL_OBJECT *menu, long user_data);
+EXTERN void graph_routines(FL_OBJECT *menu, long user_data);
+EXTERN void analysis_routines(FL_OBJECT *menu, long user_data);
+EXTERN void help_routines(FL_OBJECT *menu, long user_data);
 
 /*
 	Variable to store window geometries
 */
 
-int window_geometry[XLDLAS_NUMB_WINDOWS][4];
+EXTERN int window_geometry[XLDLAS_NUMB_WINDOWS][4];
 
 /*
 	Do we really need all these xforms objects as global variables?
@@ -307,278 +311,278 @@ int window_geometry[XLDLAS_NUMB_WINDOWS][4];
 	life easier
 */
 
-FL_FORM		*frontend;
-FL_FORM		*about_window;
-FL_FORM		*input_window;
-FL_FORM		*help_window;
+EXTERN FL_FORM		*frontend;
+EXTERN FL_FORM		*about_window;
+EXTERN FL_FORM		*input_window;
+EXTERN FL_FORM		*help_window;
 
-FL_OBJECT	*main_browser;
-FL_OBJECT	*input_browser;
-FL_OBJECT	*input_object;
-FL_OBJECT	*status_browser;
-FL_OBJECT	*help_browser;
+EXTERN FL_OBJECT	*main_browser;
+EXTERN FL_OBJECT	*input_browser;
+EXTERN FL_OBJECT	*input_object;
+EXTERN FL_OBJECT	*status_browser;
+EXTERN FL_OBJECT	*help_browser;
 
-FL_OBJECT 	*file_menu;
-FL_OBJECT 	*data_menu;
-FL_OBJECT 	*log_menu;
-FL_OBJECT 	*graph_menu;
-FL_OBJECT 	*analysis_menu;
-FL_OBJECT 	*help_menu;
-FL_OBJECT	*test_menu;
-FL_OBJECT	*filter_menu;
-	
-FL_OBJECT 	*load_button;
-FL_OBJECT 	*save_button;
-FL_OBJECT 	*describe_button;
-FL_OBJECT 	*plot_button;
-FL_OBJECT 	*regress_button;
-FL_OBJECT 	*preferences_button;
-FL_OBJECT 	*clear_button;
+EXTERN FL_OBJECT 	*file_menu;
+EXTERN FL_OBJECT 	*data_menu;
+EXTERN FL_OBJECT 	*log_menu;
+EXTERN FL_OBJECT 	*graph_menu;
+EXTERN FL_OBJECT 	*analysis_menu;
+EXTERN FL_OBJECT 	*help_menu;
+EXTERN FL_OBJECT	*test_menu;
+EXTERN FL_OBJECT	*filter_menu;
 
-FL_OBJECT	*general_help_button;
-FL_OBJECT	*file_help_button;
-FL_OBJECT	*data_help_button;
-FL_OBJECT	*log_help_button;
-FL_OBJECT	*graph_help_button;
-FL_OBJECT	*analysis_help_button;
-FL_OBJECT	*license_help_button;
-FL_OBJECT	*tutorial_help_button;
-FL_OBJECT	*test_help_button;
-FL_OBJECT	*filter_help_button;
-FL_OBJECT	*horizontal_slider;
+EXTERN FL_OBJECT 	*load_button;
+EXTERN FL_OBJECT 	*save_button;
+EXTERN FL_OBJECT 	*describe_button;
+EXTERN FL_OBJECT 	*plot_button;
+EXTERN FL_OBJECT 	*regress_button;
+EXTERN FL_OBJECT 	*preferences_button;
+EXTERN FL_OBJECT 	*clear_button;
 
-FL_OBJECT	*name_input;
-FL_OBJECT	*desc_input;
+EXTERN FL_OBJECT	*general_help_button;
+EXTERN FL_OBJECT	*file_help_button;
+EXTERN FL_OBJECT	*data_help_button;
+EXTERN FL_OBJECT	*log_help_button;
+EXTERN FL_OBJECT	*graph_help_button;
+EXTERN FL_OBJECT	*analysis_help_button;
+EXTERN FL_OBJECT	*license_help_button;
+EXTERN FL_OBJECT	*tutorial_help_button;
+EXTERN FL_OBJECT	*test_help_button;
+EXTERN FL_OBJECT	*filter_help_button;
+EXTERN FL_OBJECT	*horizontal_slider;
 
-FL_FORM		*variable_window;
-FL_OBJECT	*variable_browser;
+EXTERN FL_OBJECT	*name_input;
+EXTERN FL_OBJECT	*desc_input;
 
-FL_FORM		*rename_window;
-FL_OBJECT	*rename_browser;
+EXTERN FL_FORM		*variable_window;
+EXTERN FL_OBJECT	*variable_browser;
 
-FL_FORM		*summarize_window;
-FL_OBJECT	*summarize_browser;
-FL_OBJECT	*summarize_from_counter;
-FL_OBJECT	*summarize_to_counter;
+EXTERN FL_FORM		*rename_window;
+EXTERN FL_OBJECT	*rename_browser;
 
-FL_FORM		*drop_window;
-FL_OBJECT	*drop_browser;
-FL_OBJECT	*drop_from_counter;
-FL_OBJECT	*drop_to_counter;
+EXTERN FL_FORM		*summarize_window;
+EXTERN FL_OBJECT	*summarize_browser;
+EXTERN FL_OBJECT	*summarize_from_counter;
+EXTERN FL_OBJECT	*summarize_to_counter;
 
-FL_FORM		*list_window;
-FL_OBJECT	*list_browser;
-FL_OBJECT	*list_from_counter;
-FL_OBJECT	*list_to_counter;
+EXTERN FL_FORM		*drop_window;
+EXTERN FL_OBJECT	*drop_browser;
+EXTERN FL_OBJECT	*drop_from_counter;
+EXTERN FL_OBJECT	*drop_to_counter;
 
-FL_FORM		*corr_window;
-FL_OBJECT	*corr_browser;
-FL_OBJECT	*corr_from_counter;
-FL_OBJECT	*corr_to_counter;
+EXTERN FL_FORM		*list_window;
+EXTERN FL_OBJECT	*list_browser;
+EXTERN FL_OBJECT	*list_from_counter;
+EXTERN FL_OBJECT	*list_to_counter;
 
-FL_FORM		*regress_window;
-FL_OBJECT	*regress1_browser;
-FL_OBJECT	*regress2_browser;
-FL_OBJECT	*regress_from_counter;
-FL_OBJECT	*regress_to_counter;
+EXTERN FL_FORM		*corr_window;
+EXTERN FL_OBJECT	*corr_browser;
+EXTERN FL_OBJECT	*corr_from_counter;
+EXTERN FL_OBJECT	*corr_to_counter;
 
-FL_FORM		*graph_window;
-FL_OBJECT	*xvar_browser;
-FL_OBJECT	*yvar_browser;
-FL_OBJECT	*choose_hist_button;
-FL_OBJECT	*choose_plot_button;
-FL_OBJECT	*graph_save_input;
-FL_OBJECT	*graph_format_input;
-FL_OBJECT	*graph_options_input;
-FL_OBJECT	*graph_key_choice;
-FL_OBJECT	*graph_title_input;
-FL_OBJECT	*graph_xlabel_input;
-FL_OBJECT	*graph_ylabel_input;
-FL_OBJECT	*graph_from_counter;
-FL_OBJECT	*graph_to_counter;
-FL_OBJECT	*graph_bar_counter;
-FL_OBJECT	*graph_key_button;
-FL_OBJECT	*graph_normal_button;
-FL_OBJECT	*graph_overwrite_button;
-FL_OBJECT	*fit_variable_input;
-FL_OBJECT	*fit_overwrite_button;
-FL_OBJECT	*graph_xrange_auto_button;
-FL_OBJECT	*graph_xrange_from_counter;
-FL_OBJECT	*graph_xrange_to_counter;
-FL_OBJECT	*graph_yrange_auto_button;
-FL_OBJECT	*graph_yrange_from_counter;
-FL_OBJECT	*graph_yrange_to_counter;
+EXTERN FL_FORM		*regress_window;
+EXTERN FL_OBJECT	*regress1_browser;
+EXTERN FL_OBJECT	*regress2_browser;
+EXTERN FL_OBJECT	*regress_from_counter;
+EXTERN FL_OBJECT	*regress_to_counter;
 
+EXTERN FL_FORM		*graph_window;
+EXTERN FL_OBJECT	*xvar_browser;
+EXTERN FL_OBJECT	*yvar_browser;
+EXTERN FL_OBJECT	*choose_hist_button;
+EXTERN FL_OBJECT	*choose_plot_button;
+EXTERN FL_OBJECT	*graph_save_input;
+EXTERN FL_OBJECT	*graph_format_input;
+EXTERN FL_OBJECT	*graph_options_input;
+EXTERN FL_OBJECT	*graph_key_choice;
+EXTERN FL_OBJECT	*graph_title_input;
+EXTERN FL_OBJECT	*graph_xlabel_input;
+EXTERN FL_OBJECT	*graph_ylabel_input;
+EXTERN FL_OBJECT	*graph_from_counter;
+EXTERN FL_OBJECT	*graph_to_counter;
+EXTERN FL_OBJECT	*graph_bar_counter;
+EXTERN FL_OBJECT	*graph_key_button;
+EXTERN FL_OBJECT	*graph_normal_button;
+EXTERN FL_OBJECT	*graph_overwrite_button;
+EXTERN FL_OBJECT	*fit_variable_input;
+EXTERN FL_OBJECT	*fit_overwrite_button;
+EXTERN FL_OBJECT	*graph_xrange_auto_button;
+EXTERN FL_OBJECT	*graph_xrange_from_counter;
+EXTERN FL_OBJECT	*graph_xrange_to_counter;
+EXTERN FL_OBJECT	*graph_yrange_auto_button;
+EXTERN FL_OBJECT	*graph_yrange_from_counter;
+EXTERN FL_OBJECT	*graph_yrange_to_counter;
 
+EXTERN 
 
-FL_FORM		*att_window;
-FL_OBJECT	*att_point_counter;
-FL_OBJECT	*att_line_counter;
+EXTERN FL_FORM		*att_window;
+EXTERN FL_OBJECT	*att_point_counter;
+EXTERN FL_OBJECT	*att_line_counter;
 
-FL_FORM		*ga_window;
-FL_OBJECT	*ga_chart;
-FL_OBJECT	*ga_from_counter;
-FL_OBJECT	*ga_to_counter;
-FL_OBJECT	*ga_cycles_counter;
-FL_OBJECT	*ga_update_counter;
-FL_OBJECT	*ga_mutate_counter;
-FL_OBJECT	*ga_maxreal_counter;
-FL_OBJECT	*ga_bitsize_counter;
-FL_OBJECT	*ga_poolsize_counter;
-FL_OBJECT	*ga_perturbe_counter;
-FL_OBJECT	*ga_tolerance_counter;
-FL_OBJECT	*ga_swap_counter;
-FL_OBJECT	*ga_cross_counter;
-FL_OBJECT	*ga_yvar_browser;
-FL_OBJECT	*ga_xvars_browser;
-FL_OBJECT	*ga_force_button;
-FL_OBJECT	*ga_mutate_button;
-FL_OBJECT	*ga_cross_button;
-FL_OBJECT	*ga_perturbe_button;
-FL_OBJECT	*ga_save_input;
-FL_OBJECT	*ga_overwrite_button;
-FL_OBJECT	*ga_go_button;
-FL_OBJECT	*ga_stop_button;
-FL_OBJECT	*ga_done_button;
+EXTERN FL_FORM		*ga_window;
+EXTERN FL_OBJECT	*ga_chart;
+EXTERN FL_OBJECT	*ga_from_counter;
+EXTERN FL_OBJECT	*ga_to_counter;
+EXTERN FL_OBJECT	*ga_cycles_counter;
+EXTERN FL_OBJECT	*ga_update_counter;
+EXTERN FL_OBJECT	*ga_mutate_counter;
+EXTERN FL_OBJECT	*ga_maxreal_counter;
+EXTERN FL_OBJECT	*ga_bitsize_counter;
+EXTERN FL_OBJECT	*ga_poolsize_counter;
+EXTERN FL_OBJECT	*ga_perturbe_counter;
+EXTERN FL_OBJECT	*ga_tolerance_counter;
+EXTERN FL_OBJECT	*ga_swap_counter;
+EXTERN FL_OBJECT	*ga_cross_counter;
+EXTERN FL_OBJECT	*ga_yvar_browser;
+EXTERN FL_OBJECT	*ga_xvars_browser;
+EXTERN FL_OBJECT	*ga_force_button;
+EXTERN FL_OBJECT	*ga_mutate_button;
+EXTERN FL_OBJECT	*ga_cross_button;
+EXTERN FL_OBJECT	*ga_perturbe_button;
+EXTERN FL_OBJECT	*ga_save_input;
+EXTERN FL_OBJECT	*ga_overwrite_button;
+EXTERN FL_OBJECT	*ga_go_button;
+EXTERN FL_OBJECT	*ga_stop_button;
+EXTERN FL_OBJECT	*ga_done_button;
 
-FL_FORM		*log_window;
-FL_OBJECT	*log_verbose_button;
-FL_OBJECT	*log_on_button;
-FL_OBJECT	*log_file_input;
-FL_OBJECT	*log_view_button;
-FL_OBJECT	*log_print_button;
-FL_OBJECT	*log_done_button;
+EXTERN FL_FORM		*log_window;
+EXTERN FL_OBJECT	*log_verbose_button;
+EXTERN FL_OBJECT	*log_on_button;
+EXTERN FL_OBJECT	*log_file_input;
+EXTERN FL_OBJECT	*log_view_button;
+EXTERN FL_OBJECT	*log_print_button;
+EXTERN FL_OBJECT	*log_done_button;
 
-FL_FORM		*htmllog_window;
-FL_OBJECT	*htmllog_verbose_button;
-FL_OBJECT	*htmllog_on_button;
-FL_OBJECT	*htmllog_file_input;
-FL_OBJECT	*htmllog_view_button;
-FL_OBJECT	*htmllog_done_button;
+EXTERN FL_FORM		*htmllog_window;
+EXTERN FL_OBJECT	*htmllog_verbose_button;
+EXTERN FL_OBJECT	*htmllog_on_button;
+EXTERN FL_OBJECT	*htmllog_file_input;
+EXTERN FL_OBJECT	*htmllog_view_button;
+EXTERN FL_OBJECT	*htmllog_done_button;
 
-FL_FORM		*texlog_window;
-FL_OBJECT	*texlog_verbose_button;
-FL_OBJECT	*texlog_on_button;
-FL_OBJECT	*texlog_file_input;
-FL_OBJECT	*texlog_source_button;
-FL_OBJECT	*texlog_dvi_button;
-FL_OBJECT	*texlog_print_button;
-FL_OBJECT	*texlog_done_button;
+EXTERN FL_FORM		*texlog_window;
+EXTERN FL_OBJECT	*texlog_verbose_button;
+EXTERN FL_OBJECT	*texlog_on_button;
+EXTERN FL_OBJECT	*texlog_file_input;
+EXTERN FL_OBJECT	*texlog_source_button;
+EXTERN FL_OBJECT	*texlog_dvi_button;
+EXTERN FL_OBJECT	*texlog_print_button;
+EXTERN FL_OBJECT	*texlog_done_button;
 
-FL_FORM		*viewfile_window;
-FL_OBJECT	*viewfile_browser;
+EXTERN FL_FORM		*viewfile_window;
+EXTERN FL_OBJECT	*viewfile_browser;
 
-FL_FORM		*abort_window;
-FL_OBJECT	*general_abort_button;
+EXTERN FL_FORM		*abort_window;
+EXTERN FL_OBJECT	*general_abort_button;
 
-FL_FORM		*prefs_window;
-FL_OBJECT	*prefs_quick_dropping_button;
-FL_OBJECT	*prefs_graph_key_on_button;
-FL_OBJECT	*prefs_graph_overwrite_on_button;
-FL_OBJECT	*prefs_graph_normal_on_button;
-FL_OBJECT	*prefs_ga_cross_ok_button;
-FL_OBJECT	*prefs_ga_mutate_ok_button;
-FL_OBJECT	*prefs_ga_force_button;
-FL_OBJECT	*prefs_ga_perturbe_ok_button;
-FL_OBJECT	*prefs_pearls_of_wisdom_button;
-FL_OBJECT	*prefs_numb_bars_counter;
-FL_OBJECT	*prefs_ga_cycles_counter;
-FL_OBJECT	*prefs_ga_update_counter;
-FL_OBJECT	*prefs_ga_mutate_counter;
-FL_OBJECT	*prefs_ga_maxreal_counter;
-FL_OBJECT	*prefs_ga_bitsize_counter;
-FL_OBJECT	*prefs_ga_poolsize_counter;
-FL_OBJECT	*prefs_ga_swap_counter;
-FL_OBJECT	*prefs_ga_cross_counter;
-FL_OBJECT	*prefs_ga_perturbe_counter;
-FL_OBJECT	*prefs_ga_tolerance_counter;
-FL_OBJECT	*prefs_missing_value_input;
-FL_OBJECT	*prefs_graph_output_format_input;
-FL_OBJECT	*prefs_graph_output_options_input;
-FL_OBJECT	*prefs_gnuplot_geometry_input;
-FL_OBJECT	*prefs_print_command_input;
-FL_OBJECT	*prefs_tex_command_input;
-FL_OBJECT	*prefs_dviview_command_input;
-FL_OBJECT	*prefs_dviprint_command_input;
-FL_OBJECT	*prefs_tex_preamble_input;
-FL_OBJECT	*prefs_tex_graphmacrol_input;
-FL_OBJECT	*prefs_tex_graphmacror_input;
-FL_OBJECT	*prefs_nnet_annealing_button;
-FL_OBJECT	*prefs_nnet_pictex_button;
-FL_OBJECT	*prefs_nn_learn_counter;
-FL_OBJECT	*prefs_nn_cycles_counter;
-FL_OBJECT	*prefs_balloon_help_button;
-FL_OBJECT	*prefs_font_group;
-FL_OBJECT	*prefs_font_small_button;
-FL_OBJECT	*prefs_font_normal_button;
-FL_OBJECT	*prefs_font_large_button;
-FL_OBJECT	*prefs_assume_sample_button;
+EXTERN FL_FORM		*prefs_window;
+EXTERN FL_OBJECT	*prefs_quick_dropping_button;
+EXTERN FL_OBJECT	*prefs_graph_key_on_button;
+EXTERN FL_OBJECT	*prefs_graph_overwrite_on_button;
+EXTERN FL_OBJECT	*prefs_graph_normal_on_button;
+EXTERN FL_OBJECT	*prefs_ga_cross_ok_button;
+EXTERN FL_OBJECT	*prefs_ga_mutate_ok_button;
+EXTERN FL_OBJECT	*prefs_ga_force_button;
+EXTERN FL_OBJECT	*prefs_ga_perturbe_ok_button;
+EXTERN FL_OBJECT	*prefs_pearls_of_wisdom_button;
+EXTERN FL_OBJECT	*prefs_numb_bars_counter;
+EXTERN FL_OBJECT	*prefs_ga_cycles_counter;
+EXTERN FL_OBJECT	*prefs_ga_update_counter;
+EXTERN FL_OBJECT	*prefs_ga_mutate_counter;
+EXTERN FL_OBJECT	*prefs_ga_maxreal_counter;
+EXTERN FL_OBJECT	*prefs_ga_bitsize_counter;
+EXTERN FL_OBJECT	*prefs_ga_poolsize_counter;
+EXTERN FL_OBJECT	*prefs_ga_swap_counter;
+EXTERN FL_OBJECT	*prefs_ga_cross_counter;
+EXTERN FL_OBJECT	*prefs_ga_perturbe_counter;
+EXTERN FL_OBJECT	*prefs_ga_tolerance_counter;
+EXTERN FL_OBJECT	*prefs_missing_value_input;
+EXTERN FL_OBJECT	*prefs_graph_output_format_input;
+EXTERN FL_OBJECT	*prefs_graph_output_options_input;
+EXTERN FL_OBJECT	*prefs_gnuplot_geometry_input;
+EXTERN FL_OBJECT	*prefs_print_command_input;
+EXTERN FL_OBJECT	*prefs_tex_command_input;
+EXTERN FL_OBJECT	*prefs_dviview_command_input;
+EXTERN FL_OBJECT	*prefs_dviprint_command_input;
+EXTERN FL_OBJECT	*prefs_tex_preamble_input;
+EXTERN FL_OBJECT	*prefs_tex_graphmacrol_input;
+EXTERN FL_OBJECT	*prefs_tex_graphmacror_input;
+EXTERN FL_OBJECT	*prefs_nnet_annealing_button;
+EXTERN FL_OBJECT	*prefs_nnet_pictex_button;
+EXTERN FL_OBJECT	*prefs_nn_learn_counter;
+EXTERN FL_OBJECT	*prefs_nn_cycles_counter;
+EXTERN FL_OBJECT	*prefs_balloon_help_button;
+EXTERN FL_OBJECT	*prefs_font_group;
+EXTERN FL_OBJECT	*prefs_font_small_button;
+EXTERN FL_OBJECT	*prefs_font_normal_button;
+EXTERN FL_OBJECT	*prefs_font_large_button;
+EXTERN FL_OBJECT	*prefs_assume_sample_button;
 
-FL_FORM		*gen_window;
-FL_OBJECT	*gen_data_browser;
-FL_OBJECT	*gen_from_counter;
-FL_OBJECT	*gen_to_counter;
-FL_OBJECT	*gen_var_choice;
-FL_OBJECT	*gen_name_input;
-FL_OBJECT	*gen_desc_input;
-FL_OBJECT	*gen_operator_browser;
-FL_OBJECT	*gen_argument_browser;
+EXTERN FL_FORM		*gen_window;
+EXTERN FL_OBJECT	*gen_data_browser;
+EXTERN FL_OBJECT	*gen_from_counter;
+EXTERN FL_OBJECT	*gen_to_counter;
+EXTERN FL_OBJECT	*gen_var_choice;
+EXTERN FL_OBJECT	*gen_name_input;
+EXTERN FL_OBJECT	*gen_desc_input;
+EXTERN FL_OBJECT	*gen_operator_browser;
+EXTERN FL_OBJECT	*gen_argument_browser;
 
-FL_FORM		*anova_window;
-FL_OBJECT	*anova_block_browser;
-FL_OBJECT	*anova_variable_browser;
-FL_OBJECT	*anova_one_button;
-FL_OBJECT	*anova_two_button;
-FL_OBJECT	*anova_from_counter;
-FL_OBJECT	*anova_to_counter;
-FL_OBJECT	*anova_block_counter;
+EXTERN FL_FORM		*anova_window;
+EXTERN FL_OBJECT	*anova_block_browser;
+EXTERN FL_OBJECT	*anova_variable_browser;
+EXTERN FL_OBJECT	*anova_one_button;
+EXTERN FL_OBJECT	*anova_two_button;
+EXTERN FL_OBJECT	*anova_from_counter;
+EXTERN FL_OBJECT	*anova_to_counter;
+EXTERN FL_OBJECT	*anova_block_counter;
 
-FL_FORM		*nnet_window;
-FL_OBJECT	*nnet_output_browser;
-FL_OBJECT	*nnet_input_browser;
-FL_OBJECT	*nnet_variable_input;
-FL_OBJECT	*nnet_overwrite_button;
-FL_OBJECT	*nnet_annealing_button;
-FL_OBJECT	*nnet_from_counter;
-FL_OBJECT	*nnet_to_counter;
-FL_OBJECT	*nnet_cycles_counter;
-FL_OBJECT	*nnet_learn_counter;
-FL_OBJECT	*nnet_squasher_buttons;
-FL_OBJECT	*nnet_go_button;
-FL_OBJECT	*nnet_done_button;
-FL_OBJECT	*nnet_step_button;
-FL_OBJECT	*nnet_straight_button;
-FL_OBJECT	*nnet_sigmoid_button;
+EXTERN FL_FORM		*nnet_window;
+EXTERN FL_OBJECT	*nnet_output_browser;
+EXTERN FL_OBJECT	*nnet_input_browser;
+EXTERN FL_OBJECT	*nnet_variable_input;
+EXTERN FL_OBJECT	*nnet_overwrite_button;
+EXTERN FL_OBJECT	*nnet_annealing_button;
+EXTERN FL_OBJECT	*nnet_from_counter;
+EXTERN FL_OBJECT	*nnet_to_counter;
+EXTERN FL_OBJECT	*nnet_cycles_counter;
+EXTERN FL_OBJECT	*nnet_learn_counter;
+EXTERN FL_OBJECT	*nnet_squasher_buttons;
+EXTERN FL_OBJECT	*nnet_go_button;
+EXTERN FL_OBJECT	*nnet_done_button;
+EXTERN FL_OBJECT	*nnet_step_button;
+EXTERN FL_OBJECT	*nnet_straight_button;
+EXTERN FL_OBJECT	*nnet_sigmoid_button;
 
-FL_FORM		*do_nnet_window;
-FL_OBJECT	*do_nnet_chart;
-FL_OBJECT	*do_nnet_browser;
-FL_OBJECT	*nnet_hidden_counter;
-FL_OBJECT	*nnet_pictex_button;
+EXTERN FL_FORM		*do_nnet_window;
+EXTERN FL_OBJECT	*do_nnet_chart;
+EXTERN FL_OBJECT	*do_nnet_browser;
+EXTERN FL_OBJECT	*nnet_hidden_counter;
+EXTERN FL_OBJECT	*nnet_pictex_button;
 
-FL_FORM		*sign_window;
-FL_OBJECT	*sign_one_browser;
-FL_OBJECT	*sign_two_browser;
-FL_OBJECT	*sign_null_counter;
-FL_OBJECT	*sign_from_counter;
-FL_OBJECT	*sign_to_counter;
+EXTERN FL_FORM		*sign_window;
+EXTERN FL_OBJECT	*sign_one_browser;
+EXTERN FL_OBJECT	*sign_two_browser;
+EXTERN FL_OBJECT	*sign_null_counter;
+EXTERN FL_OBJECT	*sign_from_counter;
+EXTERN FL_OBJECT	*sign_to_counter;
 
-FL_FORM		*eqmean_window;
-FL_OBJECT	*eqmean_one_browser;
-FL_OBJECT	*eqmean_two_browser;
-FL_OBJECT	*eqmean_null_counter;
-FL_OBJECT	*eqmean_from_counter;
-FL_OBJECT	*eqmean_to_counter;
+EXTERN FL_FORM		*eqmean_window;
+EXTERN FL_OBJECT	*eqmean_one_browser;
+EXTERN FL_OBJECT	*eqmean_two_browser;
+EXTERN FL_OBJECT	*eqmean_null_counter;
+EXTERN FL_OBJECT	*eqmean_from_counter;
+EXTERN FL_OBJECT	*eqmean_to_counter;
 
-FL_FORM		*watson_window;
-FL_OBJECT	*watson_browser;
-FL_OBJECT	*watson_from_counter;
-FL_OBJECT	*watson_to_counter;
+EXTERN FL_FORM		*watson_window;
+EXTERN FL_OBJECT	*watson_browser;
+EXTERN FL_OBJECT	*watson_from_counter;
+EXTERN FL_OBJECT	*watson_to_counter;
 
-FL_FORM		*filter_window;
-FL_OBJECT	*filter_browser;
-FL_OBJECT	*filter_outliers_button;
-FL_OBJECT	*filter_detrend_button;
-FL_OBJECT	*filter_zo_button;
-FL_OBJECT	*filter_from_counter;
-FL_OBJECT	*filter_to_counter;
+EXTERN FL_FORM		*filter_window;
+EXTERN FL_OBJECT	*filter_browser;
+EXTERN FL_OBJECT	*filter_outliers_button;
+EXTERN FL_OBJECT	*filter_detrend_button;
+EXTERN FL_OBJECT	*filter_zo_button;
+EXTERN FL_OBJECT	*filter_from_counter;
+EXTERN FL_OBJECT	*filter_to_counter;
